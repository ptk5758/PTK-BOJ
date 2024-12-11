#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
using List = std::vector<T>;
void Solve()
{
    int n; std::cin >> n;
    List<int> list(n, 0);
    for (int i=0; i<n; i++) std::cin >> list[i];
    std::sort(list.begin(), list.end(), [](int a, int b){return a > b;});

    int max = list[0];
    for (int i=0; i<n; i++)
    {
        max = std::max(list[i] * (i + 1), max);
    }    
    std::cout << max << "\n";
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    Solve();
    return 0;
}