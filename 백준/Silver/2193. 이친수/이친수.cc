#include <iostream>

int main() {
    int n; std::cin >> n;
    long long d[91];
    d[1] = 1;
    d[2] = 1;
    for (int i=3; i<=n; i++) {
        d[i] = d[i - 1] + d[i - 2];
    }
    std::cout << d[n] << "\n";
    return 0;
}
