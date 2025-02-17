#include <iostream>
#include <string>
#include <algorithm>

typedef std::pair<int, std::string> Pair;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    int n; std::cin >> n;
    Pair *pair = new Pair[n];
    for (int i=0; i<n; i++)
    {
        std::cin >> pair[i].first >> pair[i].second;
    }
    std::stable_sort(pair, pair + n, [](Pair a, Pair b) {
        return a.first < b.first;
    });
    for (int i=0; i<n; i++)
    {
        std::cout << pair[i].first << " " << pair[i].second << "\n";
    }
    delete [] pair;
    return 0;
}
