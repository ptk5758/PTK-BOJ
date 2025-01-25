#include <iostream>
#include <string>
int main()
{
	std::string str; std::cin >> str;
	int a = 0;
	for (int i = 0; i < str.size(); i++)
	{
		char c = str[i];
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') a++;
	}
	std::cout << a << "\n";
	return 0;
}