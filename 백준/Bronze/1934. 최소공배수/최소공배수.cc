#include <iostream>

// 최대 공약수
int GCD(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int LCM(int a, int b) {
    return (a * b) / GCD(a, b);
}

void solve() {
    int a,b;
    std::cin >> a >> b;
    if (b > a) {
        int t = a;
        a = b;
        b = t;
    }
    std::cout << LCM(a, b) << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int t; std::cin >> t;
    while (t--) solve();
    return 0;
}
