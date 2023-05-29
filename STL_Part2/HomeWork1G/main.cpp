#include <iostream>
#include <list>
#include <iterator>

void printList(std::list<int> basicList) {
	for (auto& temp : basicList) {
		std::cout << temp << " ";
	}
}


int main(int argc, const char* argv[]){

	srand(time(NULL));

	std::list<int>::iterator list_begin, list_end;

	// 1) Create empty list
	std::list<int> basicList;
	std::cout << " " << std::endl;

	// 2) Add 5 element to the end of our list
	std::cout << "Task 2" << std::endl;
	for (int i = 0; i < 1; i++) {
		for (int j = 1; j < 6; j++) {
			int temp = -100 + rand() % 200;
			basicList.push_back(temp); 
		}
	}
	printList(basicList);
	std::cout << " " << std::endl;

	// 3) out element from begin of list
	std::cout << " " << std::endl;
	std::cout << "Task 3" << std::endl;
	std::cout << basicList.front() << std::endl;

	// 4) Add 2 new element to begin of list
	std::cout << " " << std::endl;
	std::cout << "Task 4" << std::endl;
	for (int i = 0; i < 2; i++) {
		int temp = -100 + rand() % 200;
		basicList.push_front(temp);
	}
	printList(basicList);
	std::cout << " " << std::endl;

	// 5) delete 4's element of list
	std::cout << " " << std::endl;
	std::cout << "Task 5" << std::endl;
	list_begin = basicList.begin();
	std::advance(list_begin, 3);
	list_begin = basicList.erase(list_begin);
	printList(basicList);
	std::cout << " " << std::endl;

	// 6) Add 3 equal element's to the 3 random position of list
	std::cout << " " << std::endl;
	std::cout << "Task 6" << std::endl;
	for (int i = 0; i < 3; i++) {
		list_begin = basicList.begin();
		std::advance(list_begin, rand() % basicList.size());
		basicList.insert(list_begin, 11);
	}
	printList(basicList);
	std::cout << " " << std::endl;

	// 7) delete the last element of list
	std::cout << " " << std::endl;
	std::cout << "Task 7" << std::endl;
	basicList.pop_back();
	printList(basicList);
	std::cout << " " << std::endl;

	// 8) delete first element of list
	std::cout << " " << std::endl;
	std::cout << "Task 8" << std::endl;
	basicList.pop_front();
	printList(basicList);
	std::cout << " " << std::endl;

	// 9) add 2 elements to the mid of list
	std::cout << " " << std::endl;
	std::cout << "Task 9" << std::endl;
	list_begin = basicList.begin();
	std::advance(list_begin, basicList.size() / 2);
	basicList.insert(list_begin, 2, 17);
	printList(basicList);
	std::cout << " " << std::endl;

	// 10) delete repeated elements
	std::cout << " " << std::endl;
	std::cout << "Task 10" << std::endl;
	basicList.sort();
	basicList.unique();
	printList(basicList);
	std::cout << " " << std::endl;

	// 11, 12) clear list
	std::cout << " " << std::endl;
	std::cout << "Task 11, 12" << std::endl;
	basicList.clear();
	if (basicList.empty()) {
		std::cout << "List successfully cleared";
	}
	else { std::cout << "Error occurred while cleaning list"; }
	std::cout << " " << std::endl;

	return 0;
}