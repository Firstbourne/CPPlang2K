#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

std::vector<std::pair<float, std::string>> vec = {
	{111.21, "private"},
	{224.88, "public"},
	{19.7, "protected"},
	{3999.1, "private"},
	{13.5, "public"}
};

void rangedOutput() {
	for (auto ind : vec) {
		std::cout << ind.first << ", " << ind.second << '\n';
	}
}

void lambdaFunction() {
	auto func = [](auto& ind) {
		if (ind.second == "public") {
			ind.first = 0;
		}
		else
			if (ind.second == "protected") {
				ind.second = "private";
			}
		std::cout << ind.first << ", " << ind.second << '\n';
	};
	std::cout << std::endl;
	for (auto& updated_vec : vec) { func(updated_vec); } 
}

int main(int argc, const char* argv[]) {

	rangedOutput();
	lambdaFunction();
}
