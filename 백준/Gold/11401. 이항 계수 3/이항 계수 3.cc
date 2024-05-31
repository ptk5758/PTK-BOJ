#include <iostream>
#define mod 1000000007
long long pow(int a, int p) {
    if (p == 0) return 1;
    if (p == 1) return a;
    long long k = pow(a, p / 2);
    if (p % 2 == 0) {
        return ((k % mod) * (k % mod)) % mod;
    } else {
        // kkap
        return (((k * k) % mod) * (a % mod)) % mod;
    }
}
long long factorial(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    long long k = ((n % mod) * (factorial(n - 1) % mod)) % mod;
    return k;
}
long long solve(int n, int k) {
    if (n == k) return 1;
    if (k == 0) return 1;
    int kp = (int) factorial(k);
    int np = (int) factorial(n);
    int kknp = (int) factorial(n - k);
    long long a = (pow(kp, mod - 2) % mod) * (pow(kknp, mod - 2) % mod) % mod;
    return np * a % mod;
}
int main() {
    int n, k;
    std::cin >> n >> k;
    std::cout << solve(n, k);
    return 0;
}
