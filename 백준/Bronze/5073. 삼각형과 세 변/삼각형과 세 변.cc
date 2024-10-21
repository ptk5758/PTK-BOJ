#include <iostream>
#include <algorithm>
#include <set>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    while (true) {
        int arr[3];
        std::set<int> s;
        for (int i=0; i<3; i++) {
            std::cin >> arr[i];
            s.insert(arr[i]);
        }
        if (!arr[0] && !arr[1] && !arr[2]) {
            break;
        }
        std::sort(arr, arr + 3);
        if (arr[2] >= arr[1] + arr[0]) {
            std::cout << "Invalid" << "\n";
            continue;
        }
        if (s.size() == 3) {
            std::cout << "Scalene" << "\n";
        } else if (s.size() == 2) {
            std::cout << "Isosceles" << "\n";
        } else {
            std::cout << "Equilateral" << "\n";
        }
        
    }
    return 0;
}
