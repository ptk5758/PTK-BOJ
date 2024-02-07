#include <iostream>

int *arr = new int;
int main() {
    int n;
    std::cin >> n;
    arr[0] = 1;
    for (int i=1; i<=n; i++) {
        arr[i] = arr[i-1] * i;
    }
    std::cout << arr[n];
    return 0;
}
