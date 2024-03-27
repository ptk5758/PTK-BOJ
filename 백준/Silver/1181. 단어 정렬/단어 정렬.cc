#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
int main () {
    int n;
    std::cin >> n;
    std::set<std::string> set;
    
    int i = n;
    while (i--) {
        std::string str;
        std::cin >> str;
        set.insert(str);
    }
    
    std::vector<std::string> vec(set.begin(), set.end());
    
    std::sort(vec.begin(), vec.end(), [](std::string a, std::string b) -> bool {
        if (a.size() == b.size()) {
            return a < b;
        } else {
            return a.size() < b.size();
        }
    });
    std::vector<std::string>::iterator it;
    for (int i=0; i<vec.size(); i++) {
        std::cout << vec[i] << "\n";
    }
    
}
