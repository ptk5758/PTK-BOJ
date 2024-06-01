#include <iostream>
long long arr[46];
long long solve(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (arr[n]) return arr[n];
    return arr[n] = solve(n-1) + solve(n-2);
}
int main() {
    int n;
    std::cin >> n;
    std::cout << solve(n);
    return 0;
}
