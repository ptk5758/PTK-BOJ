#include <iostream>
#include <vector>
struct node {
    int value;
    bool isVisted;
    std::vector<node*> linked;
    void addEdge(node *n) {
        this->linked.push_back(n);
    }
};
void dfs(node *node) {
    if (node->isVisted) return;
//    std::cout << node->value << "방문 \n";
    node->isVisted = true;
    for (int i=0; i<node->linked.size(); i++) {
        dfs(node->linked[i]);
    }
}
int main() {
    int N,M;
    int answer = 0;
    std::cin >> N >> M;
    node *nodes = new node[N];
    for (int i=1; i<=N; i++) {
        nodes[i-1].value = i;
    }
    int i = M;
    while (i--) {
        int a,b;
        std::cin >> a >> b;
        node *an = &nodes[a-1];
        node *bn = &nodes[b-1];
        an->addEdge(bn);
        bn->addEdge(an);
    }
    for (int i=0; i<N; i++) {
        node *target = &nodes[i];
        if (target->isVisted) continue;
        answer++;
        dfs(target);
    }
    std::cout << answer;
}
