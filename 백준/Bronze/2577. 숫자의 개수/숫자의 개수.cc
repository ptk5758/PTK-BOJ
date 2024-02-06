#include <iostream>
#include <string>
#include <map>

int main() {
    int a, b, c;
    long long multiple;
    std::cin >> a >> b >> c;
    multiple = a * b * c;
    std::string str = std::to_string(multiple);
    std::map<int, int> map;
    for (int i=0; i<10; i++) {
        map[i] = 0;
    }
    for (int i=0; i<str.length(); i++) {
        int key = (int) (str[i] - '0');
        map[key]++;
    }
    for (int i=0; i<10; i++) {
        std::cout << map[i] << "\n";
    }
    return 0;
}
