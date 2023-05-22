#include "Node.h"
#include <iostream>

class BinarySearchTree {
	
    Node* insertRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->value) {
            current->left = insertRecursive(current->left, value);
        }
        else if (value > current->value) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    };

    bool searchRecursive(Node* current, int value) {
        if (current == nullptr) {
            return false;
        }

        if (value == current->value) {
            return true;
        }
        else if (value < current->value) {
            return searchRecursive(current->left, value);
        }
        else {
            return searchRecursive(current->right, value);
        }
    };

public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    };

    void insert(int value) {
        root = insertRecursive(root, value);
    };

    bool search(int value) {
        return searchRecursive(root, value);
    };

};
