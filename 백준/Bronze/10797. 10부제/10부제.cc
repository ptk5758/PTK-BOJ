#include <iostream>

int main()
{
	int n; std::cin >> n;
	int result = 0;
	for (int i = 0; i < 5; i++)
	{
		int value; std::cin >> value;
		if (n == value) result++;
	}
	std::cout << result << "\n";
	return 0;
}