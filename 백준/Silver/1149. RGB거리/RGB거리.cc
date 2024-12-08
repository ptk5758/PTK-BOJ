#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> Vector;

void Solve()
{
	int n; std::cin >> n;
	std::vector<Vector> d(3, Vector(n + 1, 0)), cost(3, Vector(n + 1, 0 ));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++) 
		{
			int value; std::cin >> value;
			cost[j][i] = value;
		}
	}
	d[0][0] = cost[0][0];
	d[1][0] = cost[1][0];
	d[2][0] = cost[2][0];
	for (int i = 1; i <= n; i++)
	{
		d[0][i] = std::min(d[1][i - 1], d[2][i - 1]) + cost[0][i];
		d[1][i] = std::min(d[0][i - 1], d[2][i - 1]) + cost[1][i];
		d[2][i] = std::min(d[0][i - 1], d[1][i - 1]) + cost[2][i];
	}
	int result = std::min(d[0][n], d[1][n]);
	std::cout << std::min(result, d[2][n]) << "\n";
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	Solve();
	return 0;
}