#include <iostream>

int d[1001] = {0, };
int main()
{
    int n; std::cin >> n;
    d[1] = 1;
    d[2] = 3;
    for (int i=3; i<=n; i++)
    {
        d[i] = (d[i-2] * 2 + d[i-1]) % 10007;
    }
    std::cout << d[n] << "\n";
    return 0;
}