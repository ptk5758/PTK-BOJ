#include <iostream>
#include <vector>
typedef std::vector<int> List;
void Solve(int n, int m, List list) {
    if (m == list.size()) {
        for (int value : list) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    } else {
        for (int i=1; i<=n; i++) {
            list.push_back(i);
            Solve(n, m, list);
            list.pop_back();
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n, m; std::cin >> n >> m;
    Solve(n, m, List());
    return 0;
}
