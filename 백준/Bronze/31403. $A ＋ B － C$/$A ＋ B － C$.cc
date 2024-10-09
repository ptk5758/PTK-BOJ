#include <iostream>
#include <string>
int main() {
	int a, b, c;
	std::cin >> a >> b >> c;
	std::cout << (a + b) - c << "\n";
	std::string str;
	str = std::to_string(a) + std::to_string(b);
	std::cout << (std::stoi(str) - c) << "\n";
	return 0;
}