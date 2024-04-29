#include <iostream>
#include <map>
#include <string>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    std::map<std::string, int> map1;
    std::map<int, std::string> map2;
    for (int i=0; i<n; i++) {
        std::string str;
        std::cin >> str;
        map1.insert(std::make_pair(str, i+1));
        map2.insert(std::make_pair(i+1, str));
    }
    
    char value[21];
    for (int i=0; i<m; i++) {
        std::cin >> value;
        if (atoi(value) != 0) { // 숫자
            int num = atoi(value);
            std::cout << map2[num] << "\n";
        } else { // 문자
            std::string str(value);
            std::cout << map1[str] << "\n";
        }
    }
    return 0;
}
