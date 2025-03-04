#include <iostream>
#include <string>
int main() {
    std::string n; std::cin >> n;
    for (int i = 0; i < n.size(); i++)
    {
        char c = n[i];
        char x = std::toupper(c);
        std::cout << x;
    }
    std::cout << "\n";
    
    return 0;
}