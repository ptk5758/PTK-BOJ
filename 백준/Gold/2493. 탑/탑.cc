#include <iostream>
#include "stack"
typedef std::pair<int, int> Pair; // index, value
typedef std::stack<Pair> Stack;
int Solve(Stack &s, Pair p) {
    while (!s.empty()) {
        if (s.top().second >= p.second) {
            int result = s.top().first + 1;
            s.push(p);
            return result;
        } else {
            s.pop();
        }
    }
    s.push(p);
    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n; std::cin >> n;
    Stack s;
    for (int i=0; i<n; i++) {
        int value; std::cin >> value;
        std::cout << Solve(s, {i, value}) << " ";
    }
    std::cout << "\n";
    
    return 0;
}
