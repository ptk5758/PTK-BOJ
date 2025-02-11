#include <iostream>
int main() {
	int n; std::cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n * 2; j++)
		{
			if ((i % 2 == 1 && j % 2 == 1) || (i % 2 == 0 && j % 2 == 0)) {
				std::cout << "*";
			} else {
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}
	return 0;
}