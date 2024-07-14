#include <iostream>

int main() {
	int n; std::cin >> n;
	int x1, x2, x3;
	x1 = n / 5;
	x2 = n / 25;
	x3 = n / 125;
	std::cout << (x1 + x2 + x3) << "\n";
	return 0;
}