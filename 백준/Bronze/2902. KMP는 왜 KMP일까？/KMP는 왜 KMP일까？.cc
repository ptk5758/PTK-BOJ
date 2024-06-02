#include <iostream>

int main() {
    char line[101];
    std::cin >> line;
    int index = 0;
    std::cout << line[0];
    while (line[index] != '\0') {
        if (line[index] == '-') {
            if (line[index+1] != '\0' && line[index + 1] >= 'A' && line[index + 1] <= 'Z') {
                std::cout << line[index+1];
            }
        }
        index++;
    }
    return 0;
}
