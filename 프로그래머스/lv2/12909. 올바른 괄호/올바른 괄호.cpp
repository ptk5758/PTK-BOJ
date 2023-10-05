#include<string>
#include <iostream>
#include <stack>
bool solution(std::string s)
{
    std::stack<char> stack;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '(') stack.push('(');
        else {
            if (!stack.empty()) stack.pop();
            else return false;
        }
    }
    return stack.empty();
}