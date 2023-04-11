#include <iostream>
#include <string>
#include <queue>
int main()
{
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    // std::cout << 3%6 << "\n";
    int count;
    std::cin >> count;
    int i = count;
    std::queue<int>q;
    std::string str;    
    while (i--) {
        std::cin >> str;
        if (str == "push") {
            int value;
            std::cin >> value;
            q.push(value);            
        } else if (str == "pop") {
            if (q.empty()) {
                std::cout << -1 << "\n";
            } else {
                std::cout << q.front() << "\n";
                q.pop();
            }
        } else if (str == "size") {
            std::cout << q.size() << "\n";
        } else if (str == "empty") {
            std::cout << q.empty() << "\n";
        } else if (str == "front") {
            if (q.empty()) {
                std::cout << -1 << "\n";
            } else {
                std::cout << q.front() << "\n";
            }
        } else if (str == "back") {
            if (q.empty()) {
                std::cout << -1 << "\n";
            } else {
                std::cout << q.back() << "\n";
            }
        }
    }
}
