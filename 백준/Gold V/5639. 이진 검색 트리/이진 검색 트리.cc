#include <iostream>

struct node
{
    int value;
    node *left;
    node *right;
};

void insertNode(node* target, node* n) {
    if (target->value > n->value) {
        if (target->left) {
            insertNode(target->left, n);
        } else {
            target->left = n;
        }
    } else {
        if (target->right) {
            insertNode(target->right, n);
        } else {
            target->right = n;
        }
    }
}
void postOrder(node* target) {
    if (target != NULL) {
        postOrder(target->left);
        postOrder(target->right);
        std::cout << target->value << std::endl;
    }
}
int main() {
    node* root = NULL;
    int value;
    while (true) {
        std::cin >> value;
        if (std::cin.eof()) break;
        node* n = new node{value, NULL, NULL};
        if (root != NULL) {
            insertNode(root, n);
        } else {
            root = n;
        }
    }
    postOrder(root);
    
}
