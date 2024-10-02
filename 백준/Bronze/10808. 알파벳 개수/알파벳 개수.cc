#include <iostream>
#include <map>

int main() {
    char *line = new char [101];
    std::map<char, int> spellingMap;
    std::cin >> line;
    int index = 0;
    while (line[index] != '\0') {
        char c = line[index];
        spellingMap[c]++;
        index++;
    }
    for (char i = 'a'; i<='z'; i++) {
        std::cout << spellingMap[i] << " ";
    }
    std::cout << "\n";
    delete [] line;
    return 0;
}
