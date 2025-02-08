#include <iostream>
int main() {
	int n; std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b; std::cin >> a >> b;
		if (a >= b)
		{
			std::cout << "MMM BRAINS" << "\n";
		}
		else
		{
			std::cout << "NO BRAINS" << "\n";
		}
	}
	return 0;
}