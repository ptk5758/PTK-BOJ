#include <iostream>
#include <algorithm>
#include <vector>
typedef std::vector<int> List;
bool IsInclude(List &list, int find) {
    for (int value : list) {
        if (value == find) {
            return true;
        }
    }
    return false;
}
void Solve(List &values, int n, int m, List list) {
    if (list.size() == m) {
        for (int value : list) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    } else {
        for (int i=0; i<values.size(); i++) {
            if (IsInclude(list, values[i])) continue;
            list.push_back(values[i]);
            Solve(values, n, m, list);
            list.pop_back();
        }
    }
    
}
int main() {
    int n, m; std::cin >> n >> m;
    List list;
    while (n--) {
        int value; std::cin >> value;
        list.push_back(value);
    }
    std::sort(list.begin(), list.end());
    Solve(list, n, m, List());
    return 0;
}
