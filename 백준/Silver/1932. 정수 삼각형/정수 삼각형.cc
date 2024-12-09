#include <iostream>
#include <algorithm>

int cost[501][501] = {};
int d[501][501] = {};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n; std::cin >> n;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=i; j++)
        {
            std::cin >> cost[i][j];
        }
    }
    d[1][1] = cost[1][1];

    for (int i=1; i<=n - 1; i++)
    {
        for (int j=1; j<=i; j++)
        {
            d[i+1][j] = std::max(d[i+1][j], d[i][j] + cost[i+1][j]);
            d[i+1][j+1] = d[i][j] + cost[i+1][j+1];
        }
    }
    int max = -1;
    for (int i=1; i<=n; i++)
    {
        if (max < d[n][i]) max = d[n][i];
    }    
    std::cout << max << "\n";
    return 0;
}