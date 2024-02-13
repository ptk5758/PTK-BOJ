#include <iostream>
#include <cmath>
#include <string>

int main() {	
	std::string str;
	int n;
	std::cin >> str >> n;
	long long result = 0;
	int p = 0;
	for (int i = str.length() - 1; i >= 0; i--, p++) {
		char c = str[i];
		int value;
		if (c > '9') {
			value = (c -55);
		} else {
			value = c - '0';
		}
		result += value * std::pow(n, p);
	}
	std::cout << result;
	return 0;
}