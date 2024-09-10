#include <iostream>
#include "vector"
typedef std::vector<int> List;
bool IsInclude(List list, int value) {
    for (int i=0; i<list.size(); i++) {
        if (list[i] == value) return true;
    }
    return false;
}
void Solution(int n, int m, List list) {
    if (list.size() == m) {
        for (int value : list) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    } else {
        for (int i=1; i<=n; i++) {
            if (IsInclude(list, i)) {
                continue;
            } else {
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
