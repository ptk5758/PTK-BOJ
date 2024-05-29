#include <iostream>
long long f(long long a, long long b, long long c) {
    if (b == 1) {
        return a % c;
    }
    long long k = f(a, b / 2, c);
    if (b % 2 == 0) {
        return k * k % c;
    } else {
        return ((k * k % c) * (a % c)) % c;
    }
}
int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout <<  f(a,b,c) << "\n";
    return 0;
}
