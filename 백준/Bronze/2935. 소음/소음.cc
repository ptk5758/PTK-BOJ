#include <iostream>
#include <string>

int main() {
    std::string s1, s2, s3, *big, *small;
    std::cin >> s1 >> s2 >> s3;
    big = s1.size() >= s3.size() ? &s1 : &s3;
    small = s1.size() >= s3.size() ? &s3 : &s1;
    unsigned long temp = big->size() - small->size();
    
    if (s2 == "+") {
        while (temp--) {
            *small = '0' + *small;
        }
        for (int i=0; i<big->size(); i++) {
            if (big->at(i) == '1' && small->at(i) == '1') std::cout << 2;
            else if (big->at(i) == '1' || small->at(i) == '1') std::cout << 1;
            else std::cout << 0;
        }
        std::cout << "\n";
    } else {
        std::cout << *big;
        for (int i=0; i<small->size() - 1; i++) {
            std::cout << 0;
        }
        std::cout << "\n";
    }
    
    return 0;
}
