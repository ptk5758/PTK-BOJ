#include <iostream>
#include <vector>
typedef std::vector<int> List;
void Solve(int n, int m, List list) {
	if (list.size() == m) {
		for (int value : list) {
			std::cout << value << " ";
		}
		std::cout << "\n";
	} else {
		for (int i = 1; i <= n; i++) {
			if (list.size() > 0 && list[list.size() - 1] > i) {
				continue;
			}
			list.push_back(i);
			Solve(n, m, list);
			list.pop_back();
		}
	}
}
int main() {
	int n, m; std::cin >> n >> m;
	Solve(n, m, List());
	return 0;
}