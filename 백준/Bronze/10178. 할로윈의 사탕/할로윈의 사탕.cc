#include <iostream>
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t; std::cin >> t;
	while (t--)
	{
		int a, b; std::cin >> a >> b;
		int x = a / b;
		std::cout << "You get " << x << " piece(s) and your dad gets " << a % b << " piece(s)." << "\n";
	}
	return 0;
}