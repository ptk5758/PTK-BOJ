#include <iostream>
#include <algorithm>
#include <limits>
int main() {
	int t; std::cin >> t;
	while (t--) {
		int min = std::numeric_limits<int>::max();
		int sum = 0;
		for (int i = 0; i < 7; i++)
		{
			int value; std::cin >> value;
			if (value % 2 == 0) {
				sum += value;
				min = std::min(min, value);
			}			
		}
		std::cout << sum << " " << min << "\n";
	}
	return 0;
}