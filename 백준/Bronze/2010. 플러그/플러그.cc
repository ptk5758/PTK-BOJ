#include <iostream>
int main() {
	int n; std::cin >> n;
	int sum = 0;
	while (n--)
	{
		int value; std::cin >> value;
		sum += value - 1;
	}
	sum++;
	std::cout << sum << "\n";
	return 0;
}