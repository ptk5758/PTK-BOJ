#include <iostream>

int main() 
{
	int t; std::cin >> t;
	
	while (t--)
	{
		int sum = 0;
		int value; std::cin >> value;
		for (int i = 1; i <= value; i += 2)
		{
			sum += i;
		}
		std::cout << sum << "\n";
	}
}