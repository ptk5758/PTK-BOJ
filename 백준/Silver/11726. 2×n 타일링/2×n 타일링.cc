#include <iostream>
long long arr[1001];
long long solve(long long n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (arr[n]) return arr[n];
    return arr[n] = (solve(n - 1) + solve(n - 2)) % 10007;
}
int main() {
    int n;
    std::cin >> n;
    std::cout << solve(n);
    return 0;
}

