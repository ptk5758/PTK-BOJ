#include <iostream>
 
int gcd(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
int main() {
    int a, b; std::cin >> a >> b;
    std::cout << gcd(a, b) << "\n" << lcm(a, b) << "\n";
    return 0;
}
