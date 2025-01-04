#include <iostream>
#include <algorithm>
int main()
{
	int total = 0, max = 0;
	for (int i = 0; i < 4; i++)
	{
		int up, down; std::cin >> down >> up;
		total += up;
		total -= down;
		max = std::max(max, total);
	}
	std::cout << max << "\n";
}