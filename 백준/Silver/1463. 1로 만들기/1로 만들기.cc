#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
    int n; std::cin >> n;
    std::vector<int> d(n + 1);
    for (int i=2; i<=n; i++)
    {
        d[i] = d[i - 1] + 1;
        if (i % 2 == 0) d[i] = std::min(d[i], d[i / 2] + 1);
        if (i % 3 == 0) d[i] = std::min(d[i], d[i / 3] + 1);
    }    
    std::cout << d[n] << "\n";
    return 0;
}