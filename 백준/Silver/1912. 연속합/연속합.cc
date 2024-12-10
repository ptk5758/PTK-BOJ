#include <iostream>
#include <algorithm>

int arr[100001] = {0, };
int d[100001] = {0, };
int main()
{
    int n; std::cin >> n;
    for (int i=1; i<=n; i++) 
    {
        std::cin >> arr[i];
    }
    d[1] = arr[1];
    int max = arr[1];
    for (int i=2; i<= n; i++)
    {
        d[i] = std::max(d[i - 1] + arr[i], arr[i]);
        if (max < d[i]) max = d[i];
    }
    std::cout << max << "\n";
    return 0;
}