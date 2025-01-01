#include <iostream>
int main()
{
	int total; std::cin >> total;
	for (int i = 0; i < 9; i++)
	{
		int value; std::cin >> value;
		total -= value;
	}
	std::cout << total << "\n";
	return 0;
}