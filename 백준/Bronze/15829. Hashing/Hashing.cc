#include <iostream>
int pow(int n, int p) {
    if (p == 0) return 1;
    if (p == 1) return n;
    return n * pow(n, p - 1) % 1234567891;
}
long long solve(int n) {
    char line[n + 1]; std::cin >> line;
    long long result = 0;
    for (int i=0; i<n; i++) {
        int value = (int) line[i] - 96;
        int p = pow(31, i);
        result += value * p % 1234567891;
    }
    return result;
}
int main() {
    int n; std::cin >> n;
    std::cout << solve(n) << "\n";
    return 0;
}
