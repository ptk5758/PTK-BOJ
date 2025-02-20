#include <iostream>
#include <string>

int main() {
	std::string x; std::cin >> x;
	std::cout << std::stoi(x, nullptr, 16) << "\n";
	return 0;
}