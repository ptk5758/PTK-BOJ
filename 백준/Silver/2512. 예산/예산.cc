#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int *arr = new int[n];
    int m = 0, sum = 0;
    for (int i=0; i<n; i++) {
        std::cin >> arr[i];
        if (m < arr[i]) m = arr[i];
        sum += arr[i];
    }
    int c;
    std::cin >> c;
    if (c >= sum) {
        std::cout << m << "\n";
        return 0;
    }
    int start = 0;
    int end = c;
    int max = 0;
    while (start <= end) {
        int mid = (start + end) / 2;
        int cost = c;
        for (int i=0; i<n; i++) {
            if (arr[i] <= mid) {
                cost -= arr[i];
            } else {
                cost -= mid;
            }
        }
        if (cost >= 0 && max < mid) max = mid;
        if (cost > 0) start = mid + 1;
        else if (cost < 0) end = mid - 1;
        else break;
    }
    std::cout << max;
    
    return 0;
}
