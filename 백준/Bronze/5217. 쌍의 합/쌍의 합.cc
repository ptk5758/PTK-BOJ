#include <iostream>

int main() {
	int t; std::cin >> t;
	while (t--)
	{
		int x; std::cin >> x;		
		std::cout << "Pairs for " << x << ":";
		bool flag = false;
		for (int i = 1; i < x; i++)
		{
			for (int j = i + 1; j < x; j++)
			{
				if (i + j == x) {
					if (flag) std::cout << ",";
					std::cout << " " << i << " " << j;
					flag = true;
				}
			}
		}
		std::cout << "\n";
	}
	
	return 0;
}