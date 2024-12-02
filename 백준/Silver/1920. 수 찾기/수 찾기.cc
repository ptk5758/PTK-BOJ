#include <iostream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n; std::cin >> n;
    int* arr = new int[n];
    for (int i=0; i<n; i++)
    {
        int value; std::cin >> value;
        arr[i] = value;
    }
    std::sort(arr, arr+n);
    int m; std::cin >> m;
    while (m--)
    {
        int value; std::cin >> value;
        int start = 0;
        int end = n - 1;
        bool flag = 0;
        
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (arr[mid] == value)
            {
                flag = true;
                break;
            }
            else if (arr[mid] < value)
            {
                start = mid + 1;
            }
            else if (arr[mid] > value)
            {
                end = mid - 1;
            }
        }
        
        std::cout << flag << "\n";
    }
}
