#include <iostream>
#define FACTOR "factor"
#define MULTIPLE "multiple"
#define NEITHER "neither"
void solve(int a, int b) {
    if (a > b) {
        if (a % b == 0) {
            std::cout << MULTIPLE << "\n";
        } else {
            std::cout << NEITHER << "\n";
        }
    } else {
        if (b % a == 0) {
            std::cout << FACTOR << "\n";
        } else {
            std::cout << NEITHER << "\n";
        }
    }
}
int main() {
    while (true) {
        int a, b;
        std::cin >> a >> b;
        if (a == 0 && b == 0) break;
        solve(a,b);
    }
    return 0;
}
