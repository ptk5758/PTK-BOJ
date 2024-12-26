#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; std::cin >> n >> m;
    vector<ll> list(n + 1), sums(n + 1);
    for (int i=1; i<=n; i++) {
        cin >> list[i];
        sums[i] = list[i] + sums[i - 1];
    }
    
    int p1 = 0, p2 = 0;
    int result = 0;
    while (p1 <= n && p2 <= n)
    {
        ll value = sums[p2] - sums[p1];
        if (value < m) {
            p2++;
        } else {
            if (result == 0) {
                result = p2 - p1;
            } else {
                result = min(result, p2 - p1);
            }
            p1++;
        }
    }
    std::cout << result << "\n";
    
    return 0;
}
