#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int arr[501][502] = { 0, };
std::vector<std::string> split(std::string str) {
	std::stringstream ss(str);
	std::vector<std::string> result;
	std::string temp;
	while (std::getline(ss, temp, ' ')) {
		result.push_back(temp);
	}
	return result;
}
int main() {	
	std::string str;
	std::getline(std::cin, str);
	int n = std::stoi(str);
	for (int i = 0; i < n; i++) {
		std::getline(std::cin, str);
		std::vector<std::string> nums = split(str);
		for (int j = 0; j < nums.size(); j++) {
			arr[i][j] = std::stoi(nums[j]);
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 0; j < i; j++) {
			int max;
			if (arr[i][j] > arr[i][j + 1])
				max = arr[i][j];
			else
				max = arr[i][j + 1];
			arr[i - 1][j] += max;
		}
	}
	std::cout << arr[0][0];
	return 0;
}