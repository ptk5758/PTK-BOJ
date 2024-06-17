#include <iostream>
#include <stack>
int main() {
	int n, k;
	std::cin >> n >> k;
	std::stack<int> stack;
	while (n--) {
		int value;
		std::cin >> value;
		stack.push(value);
	}

	int count = 0;
	while (!stack.empty()) {
		int target = stack.top();
		stack.pop();
		if (target > k) continue;
		int cnt = 0;
		while (cnt * target <= k) {
			cnt++;
		}
		count += --cnt;
		k -= target * cnt;
	}
	std::cout << count << "\n";
	return 0;
}