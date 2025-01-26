#include <iostream>
int main() {
	int t; std::cin >> t;
	while (t--)
	{
		int v, e; std::cin >> v >> e;
		std::cout << 2 - (v - e) << "\n";
	}
	return 0;
}