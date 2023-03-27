#include <iostream>
#include <stack>
#include <deque>
#include <list>

enum Menu
{
	addElement = 1,
	deleteChoosenElement = 2,
	printStack = 3,
	clearStack = 4,
	quit = 5
};

void viewStack(std::stack<int> basicStack) {
	auto view = basicStack._Get_container();
	if (basicStack.empty()) {
		std::cout << "Stack is empty" << std::endl;
		return;
	} else {
		std::cout << '\n' << "Current stack is: " << std::endl;
		for (int i = basicStack.size() - 1; i >= 0; i--) {
			std::cout << view[i] << std::endl;
		}
	}
}

void printTaskStack(std::stack<int> basicStack) {
	std::list<int> basicList;
	if ((basicStack).empty()) {
		std::cout << '\n' << "Stack is empty" << std::endl;
		return;
	}
	while (!((basicStack).empty())) {
		basicList.push_back((basicStack).top());
		(basicStack).pop();
	}
	std::cout << std::endl;
	for (int temp : basicList) {
		printf("\t| %3d |\t\n", temp);
	}
	std::cout << "\t_______\t" << std::endl;
	while (!basicList.empty()) {
		(basicStack).push(basicList.back());
		basicList.pop_back();
	}
}


int main(int argc, const char* argv[]) {

	std::stack<int> basicStack;
	int user_choose;
	int user_element;
	int stackView;

	while (exit) {
		std::cout << "What you want to do with stack? " << '\n' << "1 - Add your element to stack" << '\n' << "2 - Delete element from stack" << '\n' << "3 - Print stack" << '\n' << "4 - Clear stack" << '\n' << "5 - exit" << std::endl;
		std::cin >> user_choose;

		//Menu - operations

		if (user_choose == quit) {
			std::cout << '\n' << "Exit" << std::endl;
			exit(5);
		}
		if (user_choose == addElement) {
			std::cout << '\n' << "Eneter element you want to add: " << std::endl;
			std::cin >> user_element;
			basicStack.push(user_element);
			std::cout << '\n' << "Your element successfully added to stack, do you want to see stack? 1 - Yes, 2 - No. " << std::endl;
			std::cin >> stackView;
			if (stackView == 1) {
				viewStack(basicStack);
				std::cout << std::endl;
			}
			else { std::cout << '\n' << "Back to the Menu" << std::endl; }
		}
		if (user_choose == deleteChoosenElement) {
			std::cout << "Deleting last added element from stack.." << std::endl;
			basicStack.pop();
			std::cout << '\n' << "Element successfully deleted to stack, do you want to see stack? 1 - Yes, 2 - No. " << std::endl;
			std::cin >> stackView;
			if (stackView == 1) {
				viewStack(basicStack);
				std::cout << std::endl;
			}
			else { std::cout << '\n' << "Back to the Menu" << std::endl; }
		}
		if (user_choose == printStack) {
			printTaskStack(basicStack);
		}
		if (user_choose == clearStack) {
			while (!basicStack.empty()) {
				basicStack.pop();
			}
			std::cout << "Stack successfully cleared" << std::endl;
		}
	}
}