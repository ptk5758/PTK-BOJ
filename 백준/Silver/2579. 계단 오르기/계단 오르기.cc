#include <iostream>
int d[301] = {0, };
int arr[301] = {};
int max(int a, int b) {
    return a>b?a:b;
}
int main() {
    int n;
    std::cin >> n;
    for (int i=1; i<=n; i++) {
        std::cin >> arr[i];
    }
    d[1] = arr[1];
    d[2] = arr[1] + arr[2];
    d[3] = arr[3] + max(arr[1], arr[2]);
    for (int i=4; i<=n; i++) {
        d[i] = arr[i] + max(arr[i-1] + d[i-3], d[i-2]);
    }
    std::cout << d[n] << "\n";
    return 0;
}
