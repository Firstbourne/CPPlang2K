#include "BinarySearchTree.cpp"
#include "Branch.cpp"

#include <iostream>

int main() {
	
	BinarySearchTree binarySearchTree;
	Branch btc;

	binarySearchTree.insert(8);
	binarySearchTree.insert(5);
	binarySearchTree.insert(19);
	binarySearchTree.insert(4);
	binarySearchTree.insert(6);

	btc.print(binarySearchTree.root);

	//std::cout << "Searching for 6: " << (binarySearchTree.search(6) ? "Found" : "Not found") << std::endl;
	//std::cout << "Searching for 12: " << (binarySearchTree.search(12) ? "Found" : "Not found") << std::endl;

	return 0;
}
