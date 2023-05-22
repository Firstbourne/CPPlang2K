#include "Node.h"

#include <iostream>
#include <string>

class Branch {
	Branch* prev_lvl;
	std::string str;

	void printTree(Node* root, Branch* prev_lvl, bool isLeft) {
		if (root == nullptr) {
			return;
		}
		std::string prev_str = "    ";
		Branch* branch = new Branch(prev_lvl, prev_str);
		printTree(root->right, branch, true);

		if (!prev_lvl) {
			branch->str = "---";
		}
		else if (isLeft) {
			branch->str = ".---";
			prev_str = "   |";
		}
		else {
			branch->str = "'---";
			prev_lvl->str = prev_str;
		}

		showBranch(branch);
		std::cout << " " << root->value << std::endl;

		if (prev_lvl) {
			prev_lvl->str = prev_str;
		}
		branch->str = "   |";

		printTree(root->left, branch, false);
	};

public:
	Branch() {};

	Branch(Branch* prev_lvl, std::string str) {
		this->prev_lvl = prev_lvl;
		this->str = str;
	};

	void showBranch(Branch* lvl) {
		if (lvl == nullptr) {
			return;
		}
		showBranch(lvl->prev_lvl);
		std::cout << lvl->str;
	};

	void print(Node* root) {
		printTree(root, nullptr, false);
	};

};