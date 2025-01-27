#include <iostream>
#include <string>
int main() {
	while (true) {
		std::string str;
		std::getline(std::cin, str);
		if (str == "END") break;
		for (int i = str.size() - 1; i >= 0; i--)
		{
			std::cout << str[i];
		}
		std::cout << "\n";

	}
	return 0;
}