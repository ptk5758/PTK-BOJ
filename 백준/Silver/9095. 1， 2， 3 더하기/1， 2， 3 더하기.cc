#include <iostream>
int d[11] = {0, 1, 2, 4, };
int solve(int n) {
    for (int i=4; i<=n; i++) {
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }
    return d[n];
}
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int value;
        std::cin >> value;
        std::cout << solve(value) << "\n";
    }
    return 0;
}
