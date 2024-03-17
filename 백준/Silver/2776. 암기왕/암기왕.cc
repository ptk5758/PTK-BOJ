#include <iostream>
#include <set>
int main() {
    int t;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::set<int> set;
        while (n--) {
            int value;
            std::cin >> value;
            set.insert(value);
        }
        int m;
        std::cin >> m;
        while (m--) {
            int value;
            std::cin >> value;
            std::cout << set.count(value) << "\n";
        }
    }
}
