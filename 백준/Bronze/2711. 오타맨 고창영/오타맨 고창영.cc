#include <iostream>
#include <string>
int main()
{
	int t; std::cin >> t;
	while (t--)
	{
		int n;
		std::string str;
		std::cin >> n >> str;
		str.erase(str.begin() + n - 1);
		std::cout << str << "\n";
	}
}