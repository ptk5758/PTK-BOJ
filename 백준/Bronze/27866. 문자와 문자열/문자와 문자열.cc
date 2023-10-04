#include <iostream>
int main() {
    char word[1001];
    int value;
    std::cin >> word >> value;
    std::cout << word[value - 1];
}
