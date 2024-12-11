#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
using List = std::vector<T>;
using Pair = std::pair<int, int>;

void Solve()
{
    int n; std::cin >> n;
    List<int> a(n, 0);
    List<Pair> b(n);
    for (int i=0; i<n; i++) std::cin >> a   [i];
    for (int i=0; i<n; i++) {
        std::cin >> b[i].first;
        b[i].second = i;
    }    
    std::sort(b.begin(), b.end());
    std::sort(a.begin(), a.end(), [](int a, int b) { return a > b; });
    int result = 0;
    for (int i=0; i<a.size(); i++)
    {
        result += a[i] * b[i].first;
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