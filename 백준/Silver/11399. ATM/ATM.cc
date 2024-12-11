#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
using List = std::vector<T>;

void Solve()
{
    int n; std::cin >> n;
    List<int> list(n, 0), sums(n, 0);
    for (int i=0; i<n; i++) std::cin >> list[i];
    std::sort(list.begin(), list.end());
    sums[0] = list[0];
    int result = sums[0];
    for (int i=1; i<n; i++) 
    {
        sums[i] = sums[i - 1] + list[i];
        result += sums[i];
    }
    std::cout << result << "\n";
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    Solve();
    
    return 0;
}