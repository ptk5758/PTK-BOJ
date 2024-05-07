#include <iostream>

int main() {
    int sum = 0;
    int value;
    for (int i=0; i<5; i++) {
        std::cin >> value;
        sum += value * value;
    }
    std::cout << sum % 10;
}
