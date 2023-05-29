#include "SyntaxTree.cpp"
#include <iostream>

int main() {
	SyntaxTree tree;
	tree.insert("+");
	tree.insert("5");
	tree.insert("*");
	tree.insert("10");
	tree.insert("20");
	std::cout << tree.evaluate();
	return 0;
}