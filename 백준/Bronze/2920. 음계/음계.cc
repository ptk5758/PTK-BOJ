#include <iostream>
#include <string>
int main() {
	std::string str = "";
	int value;
	for (int i = 0; i < 8; i++) {
		std::cin >> value;
		str += std::to_string(value);
	}
	if ("12345678" == str) {
		std::cout << "ascending";
	} else if ("87654321" == str) {
		std::cout << "descending";
	} else {
		std::cout << "mixed";
	}
	return 0;
}