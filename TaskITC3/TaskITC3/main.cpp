#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

void vecPrint(std::vector<int> fVector) {
	for (auto& temp : fVector) {
		std::cout << temp << " ";
	}
	std::cout << std::endl;
}

int main(int argc, const char* argv) {

	srand(time(0));

	std::cout << "Hello!" << std::endl;

	std::vector<int> fVector(20);

	// 1) Fill vect. = 0

	std::cout << "Task 1" << std::endl;
	for (int i = 0; i < 20; i++) {
		std::cout << fVector[i] << " ";
	}
	std::cout << "" << std::endl;

	// 2) Fill vect. = rand ( -100 <> 100 )

	std::cout << "" << std::endl;
	std::cout << "Task 2" << std::endl;
	for (int i = 0; i < 20; i++) {
		fVector[i] = -100 + rand() % (100 - (-100) + 1);
		std::cout << fVector[i] << " ";
	}
	std::cout << "" << std::endl;

	// 3) Min Max elem.

	std::cout << "" << std::endl;
	std::cout << "Task 3" << std::endl;
	std::cout << "Min Element = " << *min_element(fVector.begin(), fVector.end()) << std::endl;
	std::cout << "Max Element = " << *max_element(fVector.begin(), fVector.end()) << std::endl;

	// 4) Sort vect.

	std::cout << "" << std::endl;
	std::cout << "Task 4" << std::endl;
	std::sort(fVector.begin(), fVector.end());
	for (const auto& i : fVector) {
		std::cout << i << ' ';
	}
	std::cout << "" << std::endl;

	// 5) Adding 4 new elem. to vect.end

	std::cout << "" << std::endl;
	std::cout << "Task 5" << std::endl;
	fVector.insert(fVector.end(), { 11, 13, -15, -17 });
	for (int i = 0; i < fVector.size(); i++) {
		std::cout << fVector[i] << " ";
	}
	std::cout << "" << std::endl;

	// 6) If elem < 10 then elem = 0

	std::cout << "" << std::endl;
	std::cout << "Task 6" << std::endl;
	for (int i = 0; i < fVector.size(); i++) {
		if (fVector[i] < 10) {
			fVector[i] = 0;
		}
		std::cout << fVector[i] << " ";
	}
	std::cout << "" << std::endl;

	// 7) If fvec[i] > 20 then output it

	std::cout << "" << std::endl;
	std::cout << "Task 7" << std::endl;
	std::cout << "Elements > 20 : ";
	for (int i = 0; i < fVector.size(); i++) {
		if (fVector[i] > 20) {
			int temp;
			temp = fVector[i];
			std::cout << temp << " ";
		}
	}
	std::cout << "" << std::endl;

	// 8) if fvec[i] / 2 = 0 then fvec[i] * 3

	std::cout << "" << std::endl;
	std::cout << "Task 8" << std::endl;
	for (int i = 0; i < fVector.size(); i++) {
		if (fVector[i] % 2 == 0) {
			fVector[i] = fVector[i] * 3;
		}
		std::cout << fVector[i] << " ";
	}
	std::cout << "" << std::endl;

	// 9) random shuffled elements

	std::cout << "" << std::endl;
	std::cout << "Task 9" << std::endl;
	std::random_shuffle(fVector.begin(), fVector.end());
	vecPrint(fVector);
	std::cout << "" << std::endl;

	// 10) if fvec[i] > 50 then del fvec[i]
	
	std::cout << "" << std::endl;
	std::cout << "Task 10" << std::endl;
	bool flag = true;
	while (flag == true) {
		for (auto iterator = begin(fVector); iterator != end(fVector); ++iterator) {
			flag = false;
			if (*iterator > 50) {
				fVector.erase(iterator);
				flag = true;
				break;
			}
		}
	}
	vecPrint(fVector);
	std::cout << "" << std::endl;

	// 11) Print count of elements, if fvec[i] % 2 == 0 - del fvec[i], else reverse fvec

	std::cout << "" << std::endl;
	std::cout << "Task 11" << std::endl;
	if (fVector.size() % 2 != 0) {
		fVector.erase(fVector.begin() + fVector.size() - 1);
		vecPrint(fVector);
	}
	else {
		for (auto iterator = fVector.rbegin(); iterator != fVector.rend(); ++iterator) {
			std::cout << *iterator << " ";
		}
	}
	std::cout << "" << std::endl;

	// 12) Clear vector (with message)

	std::cout << "" << std::endl;
	std::cout << "Task 12" << std::endl;
	fVector.clear();
	if (fVector.size() == 0) {
		std::cout << "Vector successfully cleared";
	}
	else { std::cout << "Error occurred while cleaning vector"; }
	std::cout << "" << std::endl;

	return 0;
}