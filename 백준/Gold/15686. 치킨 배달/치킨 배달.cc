#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> Location;
typedef std::pair<Location, int> PointLocation;
typedef std::vector<Location> List;
typedef std::vector<PointLocation> ClientList;
void Solution(int m, int start, std::vector<int> &actives, List &onwers, ClientList &clients, int &result)
{
    if (actives.size() == m) {
        int sum = 0;
        for (PointLocation client : clients) {
            Location cl = client.first;
            for (int index : actives) {
                Location ol = onwers[index];
                client.second = std::min(client.second, ::abs(cl.first - ol.first) + std::abs(cl.second - ol.second));                
            }
            sum += client.second;
            client.second = 2147483647;
        }
        // std::cout << sum << '\n';
        if (result > sum) result = sum;
    } else {
        for (int i=start; i<onwers.size(); i++) {
            actives.push_back(i);
            Solution(m, i + 1, actives, onwers, clients, result);
            actives.pop_back();
        }
    }
}
int Solve()
{
    int result = 2147483647;
    int n, m; std::cin >> n >> m;
    List onwers;
    ClientList clients;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int value; std::cin >> value;
            if (value == 1) {
                clients.push_back({{i, j}, 2147483647});
            } else if (value == 2) {
                onwers.push_back({i, j});
            }
        }
    }
    std::vector<int> t;
    Solution(m, 0, t, onwers, clients, result);
    return result;
}
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cout << Solve() << "\n";
    return 0;
}