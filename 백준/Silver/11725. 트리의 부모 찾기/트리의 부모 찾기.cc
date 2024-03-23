#include <iostream>
#include <vector>

struct TreeNode {
    int value;
    bool isVisited = false;
    int parent;
    std::vector<TreeNode*> children;
    TreeNode(int val) : value(val) {}
    void addEdge(TreeNode* child) {
        children.push_back(child);
    }
};
void dfs(TreeNode *target) {
    for (TreeNode* child : target->children) {
        if (child->isVisited) continue;
        child->isVisited = true;
        child->parent = target->value;
        dfs(child);
    }
}
int main() {
    int n;
    std::cin >> n;
    std::vector<TreeNode*> nodes;
    for (int i=0; i<n; i++) {
        TreeNode *t = new TreeNode(i+1);
        nodes.push_back(t);
    }
    int i = n - 1;
    while (i--) {
        int a,b;
        std::cin >> a >> b;
        TreeNode *na = nodes[a-1];
        TreeNode *nb = nodes[b-1];
        na->addEdge(nb);
        nb->addEdge(na);
    }
    dfs(nodes[0]);
    for (int i=1; i<n; i++) {
        std::cout << nodes[i]->parent << "\n";
        
    }
}
