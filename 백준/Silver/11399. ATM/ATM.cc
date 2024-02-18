#include <iostream>
#include <algorithm>

int main() {
    int n;
    int *nums;
    std::cin >> n;
    nums = new int[n];
    for (int i=0; i<n; i++) {
        int value;
        std::cin >> value;
        nums[i] = value;
    }
    std::sort(&nums[0], &nums[n]);
    int sum = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            sum += nums[j];
        }
    }
    std::cout << sum;
    
    
    return 0;
}
