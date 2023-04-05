#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
struct Node
{
    int number;
    bool flag = false;
    int order = 0;
    std::vector<Node*> linkNodes;
    Node(int number) {
        this->number = number;
    }
};
bool compare(Node* a, Node* b) {
    return a->number < b->number;
}

void dfs(Node* target) {
    if (target->flag) return;
    target->flag = true;
    std::cout << target->number <<" ";
    std::sort(target->linkNodes.begin(), target->linkNodes.end(), compare);
    for (int i = 0; i < target->linkNodes.size(); i++) {
        Node* node = target->linkNodes[i];
        if (!node->flag) {
            dfs(node);
        }
    }
}

void bfs(Node* target) {
    std::queue<Node*> que;
    target->flag = true;
    que.push(target);
    while (!que.empty()) {
        Node* node = que.front();
        que.pop();
        std::sort(node->linkNodes.begin(), node->linkNodes.end(), compare);
        std::cout << node->number << " ";
        for (int i = 0; i < node->linkNodes.size(); i++) {
            Node* child = node->linkNodes[i];
            if (!child->flag) {
                child->flag = true;
                que.push(child);
            }
        }
    }
}
int main()
{
    std::vector<Node*> nodes;
    int nodeCount, edgeCount, startNode;
    std::cin >> nodeCount >> edgeCount >> startNode;

    for (int i = 1; i <= nodeCount; i++) {
        Node* n = new Node(i);
        nodes.push_back(n);
    }

    while (edgeCount--) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        nodes[a]->linkNodes.push_back(nodes[b]);
        nodes[b]->linkNodes.push_back(nodes[a]);
    }
    dfs(nodes[startNode - 1]);

    for (int i = 0; i < nodes.size(); i++) {
        nodes[i]->flag = false;
    }
    std::cout << "\n";
    bfs(nodes[startNode - 1]);

}