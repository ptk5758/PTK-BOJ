#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>

template <typename T>
using Queue = std::queue<T>;

template <typename T>
using Stack = std::stack<T>;

template <typename T>
using List = std::vector<T>;

void Solve()
{
    int n; std::cin >> n;
    List<int> list(n);
    for (int i=0; i<n; i++) std::cin >> list[i];
    std::sort(list.begin(), list.end(), [](int a, int b){ return  a > b; });
    Queue<int> queue;
    for (int i=0; i<n; i++) queue.push(list[i]);
    
    int result = 0;
    while (!queue.empty())
    {
        int current = queue.front();
        if (current <= 1) break;
        else {
            queue.pop();
            int next = queue.front();
            if (next <= 1) {
                result += current;
                break;
            } else {
                queue.pop();
                result += current * next;
            }
        }
    }
    Stack<int> s;
    while (!queue.empty())
    {
        int c = queue.front();
        if (c < 1)
        {
            s.push(c); queue.pop();
        }
        else
        {
            result += c; queue.pop();
        }
    }
    while (!s.empty())
    {
        if (s.size() != 1)
        {
            int t = s.top(); s.pop();
            int n = s.top(); s.pop();
            result += t * n;
        }
        else
        {
            result += s.top(); s.pop();
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
