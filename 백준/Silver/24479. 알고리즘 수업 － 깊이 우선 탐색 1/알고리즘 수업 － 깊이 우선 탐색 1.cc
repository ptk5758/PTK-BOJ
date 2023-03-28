#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

struct Node
{
	bool flag = false;
	int number;
	int order = 0;

	std::vector<Node*> linkNode;
	Node(int number) {
		this->number = number;
	}
};
bool compare(Node* a, Node* b) {
	// std::cout << a->number << " 와 " << b->number << " 비교 " << "\n";
	return a->number < b->number;
}
int count = 1;
void dfs(Node* target) {
	if (target->flag) return;
	target->flag = true;	
	target->order = count++;
	// std::cout << target->number <<"\n";
	std::sort(target->linkNode.begin(), target->linkNode.end(), compare);
	for (int i = 0; i < target->linkNode.size(); i++) {
		Node* node = target->linkNode[i];
		if (!node->flag) {
			dfs(node);
		}
	}
}
int main() {
	std::vector<Node*> nodes;
	int nodeCount, edgeCount, startNode;
	std::cin >> nodeCount >> edgeCount >> startNode;
	for (int i = 1; i <= nodeCount; i++) {
		Node* node = new Node(i);
		nodes.push_back(node);		
	}
	
	while (edgeCount--) {
		int a, b;
		std::cin >> a >> b;
		a--;
		b--;
		// std::cout << "A : " << nodes[a]->number << " B : " << nodes[b]->number << "\n";
		nodes[a]->linkNode.push_back(nodes[b]);
		nodes[b]->linkNode.push_back(nodes[a]);
	}
	dfs(nodes[startNode-1]);
	for (int i = 0; i < nodes.size(); i++) {
		std::cout << nodes[i]->order << "\n";
	}
}