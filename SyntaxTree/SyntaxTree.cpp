#include "Node.cpp"
class SyntaxTree {
private :
	
	std::string operations = "+-*";
	bool isValueAnOperation(std::string value) {
		if (value.size() > 1) return false;
		if (value[0] >= '0' && value[0] <= '9') return false;
		return true;
	}

	Node* insertNode(Node* node, std::string value) {
		if (node == nullptr) {
			return new Node(value);
		}

		if (node->right == nullptr) {
			node->right = insertNode(node->right, value);
		}
		else if (node->left == nullptr) {
			node->left = insertNode(node->left, value);
		}
		else if (isValueAnOperation(node->right->value)) {
			node->right = insertNode(node->right, value);
		}
		else if (isValueAnOperation(node->left->value)) {
			node->left = insertNode(node->left, value);
		}

		return node;
	}
	double evaluateNode(Node* node) {
		if (node->left == nullptr && node->right == nullptr) {
			return std::stod(node->value);
		}

		double leftValue = evaluateNode(node->left);
		double rightValue = evaluateNode(node->right);

		if (node->value == "+") {
			return leftValue + rightValue;
		}
		else if (node->value == "-") {
			return leftValue - rightValue;
		}
		else if (node->value == "*") {
			return leftValue * rightValue;
		}


		return 0;
	}

public:
	Node* root;
	Node* treeRoot;
	SyntaxTree() {
		root = nullptr;
	}

	SyntaxTree(Node* root) {
		this->root = root;
	}
	
	void insert(const std::string& value) {
		root = insertNode(root, value);
		if (treeRoot == nullptr)
			treeRoot = root;
	}

	double evaluate() {
		return evaluateNode(treeRoot);
	}

};