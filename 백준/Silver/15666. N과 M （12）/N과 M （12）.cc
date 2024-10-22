#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

typedef std::vector<int> List;
typedef std::set<List> History;
void Solve(int index, int &m, List list, List &nums, History &history) {
    if (m == list.size()) {
        if (history.count(list) == 0) {
            history.insert(list);
            for (int value : list) {
                std::cout << value << " ";
            }
            std::cout << "\n";
        }
    } else {
        for (int i=index; i<nums.size(); i++) {
            for (int j=i; j<nums.size(); j++) {
                list.push_back(nums[j]);
                Solve(j, m, list, nums, history);
                list.pop_back();
            }
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
    History history;
    Solve(0, m, List(), nums, history);
    return 0;
}
