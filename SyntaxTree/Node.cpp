#include <string>

class Node {
public:
	std::string value;
	Node* left;
	Node* right;

	Node() noexcept {
		left = nullptr;
		right = nullptr;
	}
	Node(std::string value) noexcept {
		this->value = value;
	}
};