#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> List;
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n; std::cin >> n;
    List list(n + 1, 0);
    std::vector<List> d(n + 1, List(2, 0));    
    for (int i=0; i<n; i++) {
        int value; std::cin >> value;
        list[i] = value;
    }
    if (n == 1) {
        std::cout << list[0] << "\n";
        return 0;
    }
    d[1][0] = list[0];
    d[1][1] = 0;
    d[2][0] = list[1];
    d[2][1] = list[0] + list[1];
    for (int i=3; i<=n; i++)
    {
        d[i][0] = std::max(d[i-2][0], d[i-2][1]) + list[i - 1];
        d[i][1] = d[i-1][0] + list[i - 1];
    }
    std::cout << std::max(d[n][0], d[n][1]) << "\n";
    return 0;
}