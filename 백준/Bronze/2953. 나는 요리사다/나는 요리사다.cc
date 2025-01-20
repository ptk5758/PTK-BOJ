#include <iostream>

int main() 
{
	int max = 0, value = -1;
	for (int i = 0; i < 5; i++) 
	{
		int total = 0;
		for (int j = 0; j < 4; j++) {
			int value; std::cin >> value;
			total += value;
		}
		if (value < total) {
			max = i;
			value = total;
		}
	}
	std::cout << max + 1 << " " << value << "\n";
	return 0;
}