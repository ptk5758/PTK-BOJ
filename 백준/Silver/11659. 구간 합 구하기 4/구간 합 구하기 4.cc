#include <iostream>
#include <vector>
using List = std::vector<int>;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	int n, m; std::cin >> n >> m;
	List arr(n + 1), d(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> arr[i];
		d[i] = d[i - 1] + arr[i];
	}
	for (int i = 0; i < m; i++)
	{
		int s, e; std::cin >> s >> e;

		std::cout << d[e] - d[s - 1] << "\n";
	}
}