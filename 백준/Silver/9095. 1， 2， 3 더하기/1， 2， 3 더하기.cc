#include <iostream>
#include <algorithm>
#include <vector>
std::vector<int> d(1000001);
int Solution(int value)
{
    if (d[value]) return d[value];
    return d[value] = Solution(value - 1) + Solution(value - 2) + Solution(value - 3);
}

int main()
{
    int n; std::cin >> n;
    d[0] = 0;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for (int i=0; i<n; i++)
    {
        int value; std::cin >> value;    
        std::cout << Solution(value) << "\n";    
    }
    return 0;
}