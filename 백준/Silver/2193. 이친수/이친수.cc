#include <iostream>

long long d[100] = {0, };
int main()
{
    int n; std::cin >> n;
    d[1] = 1;
    d[2] = 1;
    d[3] = 2;
    for (int i=4; i<=n; i++)
    {
        d[i] = d[i - 2] + d[i - 1];
    }

    std::cout << d[n] << "\n";
    return 0;    
}