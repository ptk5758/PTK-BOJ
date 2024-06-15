#include <iostream>
#include <stack>
char chageValue(int value) {
    return value >= 10 ? value+55 : value+'0';
}
int main() {
    int n, b; std::cin >> n >> b;
    std::stack<char> stack;
    while (n >= b) {
        stack.push(chageValue(n%b));
        n /= b;
    }
    stack.push(chageValue(n));
    
    while (!stack.empty()) {
        std::cout << stack.top();
        stack.pop();
    }
    return 0;
}
