#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> List;

void Solve(int m, int index, List &nums, List list) {
    if (m == list.size()) {
        for (int value : list) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    } else {
        for (int i=index; i<nums.size(); i++) {
            list.push_back(nums[i]);
            Solve(m, i, nums, list);
            list.pop_back();
        }
    }
    
}
int main() {
    int n, m; std::cin >> n >> m;
    List nums;
    for (int i=0; i<n; i++) {
        int value;
        std::cin >> value;
        nums.push_back(value);
    }
    std::sort(nums.begin(), nums.end());
    Solve(m, 0, nums, List());
    
    return 0;
}
