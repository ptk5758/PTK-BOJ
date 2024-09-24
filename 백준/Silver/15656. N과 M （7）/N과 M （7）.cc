#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> List;
void Solve(int n, int m, List nums, List list) {
    if (m == list.size()) {
        for (int value : list) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    } else {
        for (int i=0; i<n; i++) {
            list.push_back(nums[i]);
            Solve(n, m, nums, list);
            list.pop_back();
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);
    int n, m; std::cin >> n >> m;
    List nums;
    for (int i=0; i<n; i++) {
        int value; std::cin >> value;
        nums.push_back(value);
    }
    std::sort(nums.begin(), nums.end());
    Solve(n, m, nums, List());
    return 0;
}
