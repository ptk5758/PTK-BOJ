#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> List;
void Solve(int n, int m, int index, List nums, List list) {
	if (list.size() == m) {
		for (int value : list) {
			std::cout << value << " ";
		}
		std::cout << "\n";
	} else {
		for (int i = index; i < n; i++) {
			list.push_back(nums[i]);
			Solve(n, m, i+1, nums, list);
			list.pop_back();
		}
	}

}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n, m; std::cin >> n >> m;
	List nums;
	for (int i = 0; i < n; i++) {
		int value;
		std::cin >> value;
		nums.push_back(value);
	}
	std::sort(nums.begin(), nums.end());
	Solve(n, m, 0, nums, List());
	return 0;
}