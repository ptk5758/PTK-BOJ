#include <iostream>
#include <bitset>
#include <string>
int main() {
	int t; std::cin >> t;
	while (t--)
	{
		int n; std::cin >> n;
		std::bitset<100> bs(n);
		std::string str = bs.to_string();
		for (int i = str.size() - 1; i >= 0; i--)
		{
			if (str[i] == '1') {
				std::cout << 100 - i - 1 << " ";
			}
		}
		std::cout << "\n";
	}
	return 0;
}