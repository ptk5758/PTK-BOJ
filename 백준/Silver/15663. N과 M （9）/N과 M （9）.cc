#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef std::vector<int> List;
typedef std::set<List> Set;
void Solve(int index, int m, List &nums, List list, Set &history, std::set<int> no) {
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
            if (no.count(i) > 0) continue;
            no.insert(i);
            list.push_back(nums[i]);
            Solve(i + 1, m, nums, list, history, no);
            no.erase(i);
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
    Set s;
    Solve(0, m, nums, List(), s, std::set<int>());
}
