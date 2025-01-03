#include <iostream>
int main()
{
	int t; std::cin >> t;
	while (t--)
	{
		int total; std::cin >> total;
		int n; std::cin >> n;
		for (int i = 0; i < n; i++)
		{
			int count, price; std::cin >> count >> price;
			total += count * price;
		}
		std::cout << total << "\n";
	}
}