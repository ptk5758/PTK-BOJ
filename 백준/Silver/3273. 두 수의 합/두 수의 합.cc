#include <iostream>
#include <algorithm>

int main() {
    int a; std::cin >> a;
    int *arr = new int[a];
    for (int i=0; i<a; i++) {
        std::cin >> arr[i];
    }
    std::sort(arr, arr + a);
    int x; std::cin >> x;
    int result = 0, l = 0, r = a - 1;
    while (l < r) {
        if (arr[l] + arr[r] == x) {
            result++;
            l++;
        } else if (arr[l] + arr[r] < x) {
            l++;
        } else if (arr[l] + arr[r] > x) {
            r--;
        }
    }
    std::cout << result << "\n";
    
    return 0;
}
