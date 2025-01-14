#include <iostream>
#include <string>
#include <sstream>

int main()
{
	std::string str, buffer; std::cin >> str;
	std::stringstream ss(str);
	int count = 0;
	while (std::getline(ss, buffer, ',')) {
		count++;
	}
	std::cout << count << "\n";
	return 0;
}