#include <iostream>
int main() {
	int n; std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			std::cout << " ";
		}
		for (int j = i; j < n; j++)
		{
			std::cout << "*";
		}
		for (int j = i + 1; j < n; j++)
		{
			std::cout << "*";
		}
		std::cout << "\n";
		
	}
}