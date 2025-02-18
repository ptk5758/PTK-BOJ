#include <iostream>
#include <algorithm>

typedef std::pair<int, int> Pair;
bool compare(Pair &a, Pair &b) {
    if (a.first < b.first) {
        return true;
    } else if (a.first == b.first && a.second < b.second) {
        return true;
    } else {
        return false;
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    int n; std::cin >> n;
    Pair *p = new Pair[n];
    for (int i=0; i<n; i++)
    {
        std::cin >> p[i].first >> p[i].second;
    }
    std::sort(p, p + n, compare);
    for (int i=0; i<n; i++)
    {
        std::cout << p[i].first << " " << p[i].second << "\n";
    }
    std::cout << "\n";
    return 0;
}
