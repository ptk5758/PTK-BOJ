#include <iostream>
#include <vector>
#include <algorithm>

template <typename T1, typename T2>
using Pair = std::pair<T1, T2>;
using Work = Pair<int, int>;
using Schedule = std::vector<Work>;


void Solve()
{
    int n; std::cin >> n;
    Schedule list;
    for (int i=0; i<n; i++)
    {
        int s, e; std::cin >> s >> e;
        list.push_back({s, e});
    }
    
    std::sort(list.begin(), list.end(), [](Work a, Work b){
        if (a.second == b.second)
        {
            return a.first < b.first;
        }
        return a.second < b.second;
    });
    
    Work work = list[0];
    int result = 1;
    for (int i=1; i<list.size(); i++)
    {
        if (list[i].first >= work.second)
        {
            work = list[i];
            result++;
        }
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