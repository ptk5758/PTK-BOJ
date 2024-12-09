#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> List;
typedef std::vector<List> Board;

List d(1000001, 0), h(1000001, 0);
int main()
{
    int n; std::cin >> n;
    d[1] = 0;
    for (int i=2; i<=n; i++)
    {
        d[i] = d[i - 1] + 1;
        h[i] = i - 1;
        if (i % 2 == 0 && d[i/2] < d[i]) {
            h[i] = i / 2;
            d[i] = d[i / 2] + 1;
        }
        if (i % 3 == 0 && d[i/3] < d[i]) {
            h[i] = i / 3;
            d[i] = d[i / 3] + 1;
        }
    }
    std::cout << d[n] << "\n";
    int head = n;
    while (true)
    {
        std::cout << head << " ";
        if (head == 1) break;
        head = h[head];
    }
    return 0;
}