#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using ll = long long;
using List = std::vector<ll>;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m; std::cin >> n >> m;
	
	List list(n);
	for (int i=0; i<n; i++) std::cin >> list[i];
	std::sort(list.begin(), list.end());
	int p1 = 0, p2 = 1;
	ll min = std::numeric_limits<int>::max();
	while (p1 < n && p2 < n)
	{
		ll value = list[p2] - list[p1];
		if (value < m) {
			p2++;
		} else {
			min = std::min(min, value);
			p1++;
		}
	}

	std::cout << min << "\n";
	
	return 0;
}