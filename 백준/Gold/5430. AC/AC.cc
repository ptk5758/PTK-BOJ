#include <iostream>
#include <string>
#include <vector>
#include <sstream>
std::vector<int> split(std::string str) {
	std::vector<int> result;
	std::stringstream ss(str);
	std::string temp;
	while (std::getline(ss, temp, ',')) {
		result.push_back(std::stoi(temp));
	}
	return result;
}
void fn() {
	char p[100001];
	int n;
	std::string str;
	std::cin >> p >> n >> str;	
	std::vector<int> nums;
	if (str != "[]") {
		nums = split(str.substr(1, str.length() - 1));
	}	 
	int front = 0;
	int rear = nums.size();
	int i = 0;
	bool flag = false;
	while (p[i] != '\0') {
		if (p[i] == 'R') {
			flag = !flag;
		} else {
			if (rear - front == 0) {
				std::cout << "error" << "\n";
				return;
			}
			if (flag) { // 뒤집혀진 상태
				rear--;
			} else { // 정상
				front++;
			}
		}
		i++;
	}
	std::cout << "[";
	if (flag) {
		for (int i = rear - 1; i >= front; i--) {
			std::cout << nums[i];
			if (i != front) std::cout << ",";
		}
	} else {
		for (int i = front; i<rear;  i++) {
			std::cout << nums[i];
			if (i + 1 < rear) std::cout << ",";
		}
	}
	std::cout << "]\n";
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t;
	std::cin >> t;
	int i = t;
	while (i--) {
		fn();
	}
}