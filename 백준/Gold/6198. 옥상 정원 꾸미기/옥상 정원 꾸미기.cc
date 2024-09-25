#include <iostream>
#include "vector"
#include "stack"
typedef std::stack<int> Stack;
long long Solve(int n) {
    Stack s;
    long long result = 0;
    while (n--) {
        int value; std::cin >> value;
        if (s.empty()) {
            s.push(value);
        } else {
            while (!s.empty()) {
                if (s.top() > value) {
                    result += s.size();
                    break;
                } else {
                    s.pop();
                }
            }
            s.push(value);
        }
    }
    return result;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n; std::cin >> n;
    std::cout << Solve(n) << "\n";
    return 0;
}
