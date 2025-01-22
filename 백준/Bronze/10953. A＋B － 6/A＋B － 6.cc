#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main() {
	int n; std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::string str, buffer; std::cin >> str;
		std::stringstream ss(str);
		std::vector<int> nums;
		while (std::getline(ss, buffer, ',')) {
			nums.push_back(std::stoi(buffer));
		}
		int total = 0;
		for (int value : nums) {
			total += value;
		}
		std::cout << total << "\n";
	}
	return 0;
}