#include <iostream>
int main() {
	int n;
	std::cin >> n;
	int* weight = new int[n];
	int* height = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> weight[i] >> height[i];		
	}
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (weight[i] < weight[j] && height[i] < height[j]) cnt++;
		}
		std::cout << cnt << " ";
	}
	return 0;
}