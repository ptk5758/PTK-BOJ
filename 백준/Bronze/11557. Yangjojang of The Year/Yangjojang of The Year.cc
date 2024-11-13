#include <iostream>
#include <string>
void Solve()
{
	int n; std::cin >> n;
	int max = -1;
	std::string result;
	while (n--) {
		std::string school;
		int value;
		std::cin >> school >> value;
		if (max < value) {
			max = value;
			result = school;
		}
	}
	std::cout << result << "\n";
}
int main() {
	int t; std::cin >> t;
	while (t--) {
		Solve();
	}
	return 0;
}