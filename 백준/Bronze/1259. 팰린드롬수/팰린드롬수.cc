#include <iostream>
#include <string>
int main() {
    while (true) {
        std::string str;
        std::cin >> str;
        if (str == "0") break;
        int start = 0;
        int end = str.length() - 1;
        bool flag = true;
        while (start < end) {
            if (str[start] != str[end]) {
                flag = false;
                break;;
            }
            start++;
            end--;
        }
        if (flag)
            std::cout << "yes" << "\n";
        else
            std::cout << "no" << "\n";
    }
    return 0;
}
