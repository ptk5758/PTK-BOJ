#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio();
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::string str, temp; std::cin >> str;
    temp += str[0];
    char last = str[0];
    for (int i=1; i<str.size(); i++)
    {
        if (last != str[i]) {
            temp += str[i];
            last = str[i];
        }
    }
    int zero = 0;
    int one = 0;
    for (int i=0; i<temp.size(); i++)
    {
        if (temp[i] == '1') one++;
        else zero++;
    }
    std::cout << (zero > one ? one : zero)<< "\n";
    return 0;
}
