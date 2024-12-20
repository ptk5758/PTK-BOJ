#include <iostream>
#include <vector>
#include <queue>

template <typename T>
using List = std::vector<T>;

template <typename T>
using Queue = std::queue<T>;

using Pair = std::pair<int, int>;

int arr[100001] = {0, };
List<bool> visited(100001, false);

int main()
{
    int n, k; std::cin >> n >> k;
    Queue<Pair> queue;
    queue.push({n, 0});
    int max = 100000;
    int result = 2100000000;
    
    while (!queue.empty())
    {
        Pair p = queue.front(); queue.pop();
        int location = p.first;
        int cost = p.second;
        visited[location] = true;
        
        if (location == k)
        {
            result = std::min(result, cost);
        }
        
        if (location * 2 <= max && !visited[location * 2]) {
            queue.push({location * 2, cost});
        }
        if (location + 1 <= max && !visited[location + 1]) {
            queue.push({location + 1, cost + 1});
        }
        if (location - 1 >= 0 && !visited[location - 1]) {
            queue.push({location - 1, cost + 1});
        }
    }
    std::cout << result << "\n";
    return 0;
}
