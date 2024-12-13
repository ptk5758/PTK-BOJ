#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

template <typename T>
using List = std::vector<T>;


int main()
{
    std::string str; std::cin >> str;
    std::stringstream ss(str);
    std::string buffer;
    List<int> nums;
    List<char> opers;
    opers.push_back('+');
    for (int i=0; i<str.size(); i++)
    {
        if (str[i] == '+' || str[i] == '-') opers.push_back(str[i]);
    }
    while (std::getline(ss, buffer, '+'))
    {
        std::stringstream ss2(buffer);
        while (std::getline(ss2, buffer, '-'))
        {
            nums.push_back(std::stoi(buffer));
        }
    }
    bool isGroup = false;
    int total = 0;
    int temp = 0;
    for (int i=0; i<nums.size(); i++)
    {
        if (isGroup)
        {
            if (opers[i] == '+')
            {
                temp += nums[i];
            }
            else
            {
                i--;
                isGroup = false;
            }
        }
        else
        {
            if (opers[i] == '-')
            {
                isGroup = true;
                temp += nums[i];
                continue;
            }
            total += nums[i];
        }
    }
    std::cout << total - temp << "\n";
}