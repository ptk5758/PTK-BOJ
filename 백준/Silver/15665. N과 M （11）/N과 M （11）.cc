#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef std::vector<int> List;
typedef std::set<List> Hisotry;
void Solve(int index, int m, List &nums, List list, Hisotry &history) {
    if (list.size() == m) {
        if (history.count(list) == 0) {
            history.insert(list);
            for (int value : list) {
                std::cout << value << " ";
            }
            std::cout << "\n";
        }
    } else {
        for (int i=0; i<nums.size(); i++) {
            list.push_back(nums[i]);
            Solve(i+1, m, nums, list, history);
            list.pop_back();
        }
    }
    
}
int main() {
    int n, m; std::cin >> n >> m;
    List nums;
    for (int i=0; i<n; i++) {
        int value; std::cin >> value;
        nums.push_back(value);
    }
    std::sort(nums.begin(), nums.end());
    Hisotry history;
    Solve(0, m, nums, List(), history);
    return 0;
}
