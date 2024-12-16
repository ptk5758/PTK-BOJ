#include <iostream>

long long d[101] = {0, 1, 1, 1};

long long Solution(int a)
{
    if (a==0) return 0;
    if (d[a]) return d[a];
    return d[a] = Solution(a - 3) + Solution(a - 2);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int t; std::cin >> t;
    while (t--)
    {
        int n; std::cin >> n;
        std::cout << Solution(n) << "\n";
    }
    return 0;
}