#include <iostream>
#include <vector>
#include <set>

typedef std::vector<int> List;
std::vector<std::set<int>> groups;
bool check(std::set<int> set) {
    for (std::set<int> group : groups) {
        if (group == set) return true;
    }
    return false;
}
bool IsInclude(List list, int value) {
    for (int item : list) {
        if (item == value) return true;
    }
    return false;
}
void Solution(int n, int m, List list) {
    if (list.size() == m) {
        std::set<int> set(list.begin(), list.end());
        if (!check(set)) {
            groups.push_back(set);
            for (int i=0; i<list.size(); i++) {
                std::cout << list[i] << " ";
            }
            std::cout << "\n";
        }
        
    } else {
        for (int i=1; i<=n; i++) {
            if (!IsInclude(list, i)) {
                list.push_back(i);
                Solution(n, m, list);
                list.pop_back();
            }
        }
    }
    
}
int main() {
    int n, m; std::cin >> n >> m;
    List list;
    Solution(n, m, list);
    return 0;
}
