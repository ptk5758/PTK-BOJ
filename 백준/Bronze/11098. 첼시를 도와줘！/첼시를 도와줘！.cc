#include <iostream>
#include <string>

int main()
{
	int t; std::cin >> t;
	while (t--)
	{
		int n; std::cin >> n;
		int max = 0;
		std::string result = "";
		for (int i = 0; i < n; i++)
		{
			int value;
			std::string str;
			std::cin >> value >> str;
			if (max < value) {
				max = value;
				result = str;
			}
		}
		std::cout << result << "\n";
	}
	return 0;
}