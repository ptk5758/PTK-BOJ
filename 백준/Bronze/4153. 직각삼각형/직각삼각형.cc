#include <iostream>
#include <cmath>
#include <algorithm>
#define RIGHT "right"
#define WRONG "wrong"
void solve(int a, int b, int c) {
    bool flag = c == std::sqrt((std::pow(a, 2) + std::pow(b, 2)));
    if (flag) {
        std::cout << RIGHT << "\n";
    } else {
        std::cout << WRONG << "\n";
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    while (true) {
        int arr[3];
        for (int i=0; i<3; i++) std::cin >> arr[i];
        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) break;
        std::sort(arr, arr + 3);
        solve(arr[0], arr[1], arr[2]);
    }
    return 0;
}
