#include <iostream>
int arr[101] = {0, };
int main()
{
    std::ios::sync_with_stdio();
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n; std::cin >> n;
    for (int i=0; i<n; i++) std::cin >> arr[i];
    int result = 0;
    int top = arr[n - 1];
    for (int i=n - 2; i>=0; i--)
    {
        int now = arr[i];
        if (now >= top) {
            result += now - top + 1;
            now = top - 1;
        }
        top = now;
    }
    std::cout << result << "\n";
    return 0;
}
