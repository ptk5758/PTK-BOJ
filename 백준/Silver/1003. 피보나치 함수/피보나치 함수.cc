#include <iostream>
int d[41][2] = {
    {1,0},
    {0,1},
    {1,1}
};
int main()
{   

    int x; std::cin >> x;
    while (x--)
    {
        int n; std::cin >> n;
        for (int i=2; i<=n; i++)
        {
            d[i][0] = d[i-2][0] + d[i-1][0];
            d[i][1] = d[i-2][1] + d[i-1][1];
        }
        std::cout << d[n][0] << " " << d[n][1] << "\n";
    }


    return 0;
}