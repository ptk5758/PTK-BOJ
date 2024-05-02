#include <iostream>
int arr[21];
int fn(int n) {
    if (n == 0) return 0;
    if (arr[n] != 0) return arr[n];
    return arr[n] = fn(n - 2) + fn(n - 1);
}
int main() {
    int n;
    std::cin >> n;
    arr[1] = 1;
    int value = fn(n);
    std::cout << value;
    return 0;
}
