#include <iostream>
#include <vector>
#include <algorithm>

using Pair = std::pair<int, int>;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	int n; std::cin >> n;
	std::vector<Pair> list(n);
	std::vector<int> d(n);
	for (int i=0; i<n; i++) std::cin >> list[i].first >> list[i].second;
	for (int i=0; i<n; i++) {
		Pair p = list[i];
		if (i + p.first > n) continue;
		d[i] = d[i] + p.second;
		for (int j=i+p.first; j<n; j++)
		{
			d[j] = std::max(d[i], d[j]);
		}
	}
	int max = 0;
	for (int i=0; i<n; i++) max = std::max(max, d[i]);
	std::cout << max << "\n";
	return 0;
}