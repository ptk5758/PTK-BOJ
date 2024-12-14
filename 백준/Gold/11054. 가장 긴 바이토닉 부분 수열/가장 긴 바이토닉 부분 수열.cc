#include <iostream>
#include <algorithm>

int arr[1001] = {0, };
int da[1001] = {0, 1};
int db[1002] = {0, };
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n; std::cin >> n;
    for (int i=1; i<=n; i++) std::cin >> arr[i];
    for (int i=2; i<=n; i++)
    {
        int ai = 0;
        for (int j=i-1; j>0; j--)
        {
            if (arr[i] > arr[j])
            {
                ai = std::max(ai, da[j]);
            }
        }
        da[i] = ai + 1;
        
    }
    db[n] = 1;
    for (int i=n - 1; i>0; i--)
    {
        int index = 0;
        for (int j=i+1; j<=n; j++)
        {
            if (arr[i] > arr[j])
            {
                index = std::max(index, db[j]);
            }
        }
        db[i] = index + 1;
    }
    
    int result = 0;
    for (int i=1; i<=n; i++)
    {
        result = std::max(result, da[i] + db[i]);
    }
    std::cout << result - 1 << "\n";
    return 0;
}
