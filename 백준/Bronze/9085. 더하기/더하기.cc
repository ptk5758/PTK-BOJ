#include <iostream>
#include <string>

int main()
{
	int t; std::cin >> t;
	while (t--)
	{
		int sum = 0;
		int n; std::cin >> n;
		for (int i = 0; i < n; i++)
		{
			int value; std::cin >> value;
			sum += value;
		}
		std::cout << sum << "\n";
	}
	return 0;
}