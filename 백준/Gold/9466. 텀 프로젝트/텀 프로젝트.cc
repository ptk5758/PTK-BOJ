#include <iostream>
#include <vector>

template <typename T>
using List = std::vector<T>;
int count;

void DFS(int index, List<int> &list, List<bool> &visited, List<bool> &actived)
{
    visited[index] = true;
    int next = list[index];
    if (!visited[next])
    {
        DFS(next, list, visited, actived);
    }
    else if(!actived[next])
    {
        for (int i=next; i!=index; i=list[i])
        {
            count++;
        }
        count++;
    }
    actived[index] = true;
}
void Solve()
{

    int n; std::cin >> n;
    count = 0;
    List<int> list(n + 1, 0);
    List<bool> actived(n + 1, false);
    List<bool> visited(n + 1, false);
    for (int i=1; i<=n; i++) std::cin >> list[i];

    for (int i=1; i<=n; i++)
    {
        if (!visited[i])
        {
            DFS(i, list, visited, actived);
        }
    }
    std::cout << n - count << "\n";

}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n; std::cin >> n;
    while(n--) Solve();
    return 0;
}