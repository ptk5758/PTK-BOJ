#include <iostream>
#include <map>

struct node {
	char value;
	node* left;
	node* right;
	node (char value) {
		this->value = value;
		left = NULL;
		right = NULL;
	}
};
void preOrder(node *target) {
	if (target && target->value != '.') {
		std::cout << target->value;
		preOrder(target->left);
		preOrder(target->right);
	}
}
void inOrder(node* target) {
	if (target && target->value != '.') {
		inOrder(target->left);
		std::cout << target->value;
		inOrder(target->right);
	}
}
void postOrder(node* target) {
	if (target && target->value != '.') {
		postOrder(target->left);
		postOrder(target->right);
		std::cout << target->value;
	}
}
int main() {
	int n;
	std::cin >> n;
	char spel = 'A';
	std::map<char, node*> map;
	for (int i = 0; i < n; i++, spel++) {
		map[spel] = new node(spel);
	}
	while (n--) {
		char target, left, right;
		std::cin >> target >> left >> right;
		map[target]->left = map[left];
		map[target]->right = map[right];
	}
	preOrder(map['A']);
	std::cout << "\n";
	inOrder(map['A']);
	std::cout << "\n";
	postOrder(map['A']);
	std::cout << "\n";
}