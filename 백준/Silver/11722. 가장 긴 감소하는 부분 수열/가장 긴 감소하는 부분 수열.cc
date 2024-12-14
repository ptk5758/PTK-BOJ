#include <iostream>
#include <algorithm>

int arr[1001] = {0, };
int d[1001] = {0, };
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n; std::cin >> n;
    for (int i=1; i<=n; i++) std::cin >> arr[i];
    d[1] = 1;
    int result = d[1];
    for (int i=2; i<=n; i++)
    {
        int index = 0;
        for (int j=i-1; j>0; j--)
        {
            if (arr[i] < arr[j])
            {
                index = std::max(index, d[j]);
            }
        }
        d[i] = index + 1;
        result = std::max(result, d[i]);
    }
    std::cout << result << "\n";
    return 0;
}
