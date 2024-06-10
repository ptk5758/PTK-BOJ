#include <iostream>

int d[1000001]= {0, };
int min(int a, int b) {
    return a > b ? b : a;
}
int main() {
    int n;
    std::cin >> n;
    d[0] = 0;
    d[1] = 0;
    d[2] = 1;
    d[3] = 1;
    for (int i=4; i<=n; i++) {
        d[i] = d[i-1] + 1;
        if (i % 3 == 0) {
            d[i] = min(d[i], d[i/3] + 1);
        }
        if (i % 2 == 0) {
            d[i] = min(d[i], d[i/2] + 1);
        }
    }
    std::cout << d[n] << "\n";
    return 0;
}
