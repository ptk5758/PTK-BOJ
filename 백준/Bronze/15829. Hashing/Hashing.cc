#include <iostream>
#define mod 1234567891
long long solve(int n) {
    char line[n + 1]; std::cin >> line;
    long long result = 0, r = 1;
    for (int i=0; i<n; i++) {
        int value = (int) line[i] - 96;
        result = (result + value * r) % mod;
        r = (r * 31) % mod;
    }
    return result;
}
int main() {
    int n; std::cin >> n;
    std::cout << solve(n) << "\n";
    return 0;
}
