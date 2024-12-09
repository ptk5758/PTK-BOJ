#include <iostream>

int arr[100001] = { 0, };
void Solve()
{
    int n, m; std::cin >> n >> m;
    for (int i=1; i<=n; i++) {
        std::cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    for (int i=0; i<m; i++)
    {
        int start, end; std::cin >> start >> end;
        std::cout << arr[end] - arr[start - 1] << "\n";
    }

}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    Solve();
    return 0;
}