#include <iostream>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::map<int, int> map;
    int n;
    std::cin >> n;
    while (n--) {
        int value;
        std::cin >> value;
        map[value]++;
    }
    int m;
    std::cin >> m;
    while (m--) {
        int value;
        std::cin >> value;
        if (map.count(value) > 0) {
            std::cout << map[value];
        } else {
            std::cout << 0;
        }
        if (m != 0) std::cout << " ";
    }
}
