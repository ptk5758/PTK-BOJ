#include <iostream>
#include <stack>
char line[31];

int main() {
    std::cin >> line;
    std::stack<int> stack;
    int index = 0, temp;
    while (line[index] != '\0') {
        char c = line[index++];
        if (c == '(') {
            stack.push(-1);
        } else if (c == '[') {
            stack.push(-2);
        } else if (c == ')') {
            temp = 0;
            while (!stack.empty() && stack.top() != -1) {
                if (stack.top() == -2) {
                    std::cout << 0 << "\n";
                    return 0;
                }
                temp += stack.top();
                stack.pop();
            }
            if (stack.empty()) {
                std::cout << 0 << "\n";
                return 0;
            }
            stack.pop();
            if (temp == 0) temp = 1;
            stack.push(temp * 2);
        } else if (c == ']') {
            temp = 0;
            while (!stack.empty() && stack.top() != -2) {
                if (stack.top() == -1) {
                    std::cout << 0 << "\n";
                    return 0;
                }
                temp += stack.top();
                stack.pop();
            }
            if (stack.empty()) {
                std::cout << 0 << "\n";
                return 0;
            }
            stack.pop();
            if (temp == 0) temp = 1;
            stack.push(temp * 3);
        }
    }
    int sum = 0;
    while (!stack.empty()) {
        if (stack.top() == -1 || stack.top() == -2) {
            std::cout << 0 << "\n";
            return 0;
        }
        sum += stack.top();
        stack.pop();
    }
    std::cout << sum << "\n";
    return 0;
}
