#pragma once

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) {
        this->value = value;
        this->left = this->right = nullptr;
    };

};
