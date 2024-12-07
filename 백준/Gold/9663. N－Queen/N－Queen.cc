#include <iostream>
#include <vector>

typedef std::vector<bool> List;
bool c[40]; 
bool l[40]; 
bool r[40]; 
void Solve(int n, int y, int &result)
{
    if (y == n) {
        result++;
        return;
    }
    for (int i=0; i<n; i++)
    {
        if (c[i] || r[i+y] || l[y-i+n-1]) 
            continue;
        c[i] = 1;
        r[i+y] = 1;
        l[y-i+n-1] = 1;
        Solve(n, y + 1, result);
        c[i] = 0;
        r[i+y] = 0;
        l[y-i+n-1] = 0;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n; std::cin >> n;
    int result = 0;
    Solve(n, 0, result);
    std::cout << result << "\n";
    return 0;
}