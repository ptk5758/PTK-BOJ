#include <iostream>
#include <string>

void reverse(std::string &value) {
	for (int i = 0, j = value.size() - 1; i < j; i++, j--)
	{
		char c = value[i];
		value[i] = value[j];
		value[j] = c;
	}
}
int main() {
	std::string x, y; std::cin >> x >> y;
	reverse(x);
	reverse(y);
	int ix = std::stoi(x);
	int iy = std::stoi(y);
	std::string sum = std::to_string(ix + iy);
	reverse(sum);
	std::cout << std::stoi(sum) << "\n";
	return 0;
}