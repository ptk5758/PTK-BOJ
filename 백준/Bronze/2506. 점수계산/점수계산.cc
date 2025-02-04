#include <iostream>
int main() {
	int n; std::cin >> n;
	int sum = 0, t = 1;
	for (int i = 0; i < n; i++)
	{
		bool value; std::cin >> value;
		if (value) {
			sum += t++;
		} else {
			t = 1;
		}
	}
	std::cout << sum << "\n";
}