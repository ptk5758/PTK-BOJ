#include <iostream>
#include <set>
#include <string>
int main() {
    int n, m;
    std::set<std::string> set;
    std::cin >> n >> m;
    std::string stream;
    while (n--) {
        std::cin >> stream;
        set.insert(stream);
    }
    std::set<std::string> result;
    while (m--) {
        std::cin >> stream;
        if (set.count(stream)) {
            result.insert(stream);
        }
    }
    std::set<std::string>::iterator it;
    std::cout << result.size() << "\n";
    for (it = result.begin(); it != result.end(); it++) {
        std::cout << *it << "\n";
    }
}
