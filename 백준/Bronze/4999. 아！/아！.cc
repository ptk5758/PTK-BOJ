#include <iostream>
#include <string>

int main() {
	std::string str1;
	std::string str2;
	std::cin >> str1 >> str2;
	if (str1.length() >= str2.length()) {
		std::cout << "go" << "\n";
	} else {
		std::cout << "no" << "\n";
	}
	return 0;
}