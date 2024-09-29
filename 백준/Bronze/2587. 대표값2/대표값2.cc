#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n = 5;
    std::vector<int> vec;
    int sum = 0;
    for (int i=0; i<n; i++) {
        int value;
        std::cin >> value;
        sum += value;
        vec.push_back(value);
    }
    std::sort(vec.begin(), vec.end());
    std::cout << (int)(sum / n) << "\n";
    std::cout << vec[2] << "\n";
    return 0;
}
