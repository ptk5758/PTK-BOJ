#include <iostream>

int main()
{
	int t; std::cin >> t;
	while (t--)
	{
		int ta = 0, tb = 0;
		for (int i = 0; i < 9; i++)
		{
			int a, b; std::cin >> a >> b;
			ta += a;
			tb += b;
		}
		if (ta > tb) {
			std::cout << "Yonsei" << "\n";
		}
		else if (ta < tb) {
			std::cout << "Korea" << "\n";
		}
		else {
			std::cout << "Draw" << "\n";
		}
	}
	return 0;
}