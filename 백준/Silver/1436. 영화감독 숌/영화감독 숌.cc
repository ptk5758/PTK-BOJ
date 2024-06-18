#include <iostream>
#include <string>

bool check(int num) {
	std::string str;
	str = std::to_string(num);
	int cnt = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '6') {
			cnt++;
			if (cnt == 3) return true;
		} else {
			cnt = 0;
		}
	}
	return false;
}
int solve(int n) {
	if (n == 0) return 0;
	if (n == 1) return 666;
	int cnt = 1;
	int i = 666;
	while (true) {
		if (cnt == n) break;
		if (check(++i)) {
			cnt++;
		}
	}
	return i;
}
int main() {
	int n; std::cin >> n;
	std::cout << solve(n) << "\n";
	return 0;
}