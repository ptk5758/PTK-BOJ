#include <iostream>
#include <vector>
#include <algorithm>
int arr[9];
typedef std::vector<int> List;
int sum(List list) {
	int result = 0;
	for (int value : list) {
		result += value;
	}
	return result;
}
bool flag = false;
void solve(List list, int index) {
	if (flag) return;
	if (list.size() == 7) {
		if (sum(list) == 100) {
			std::sort(list.begin(), list.end());
			for (int i = 0; i < 7; i++) {
				std::cout << list[i] << "\n";
			}
			flag = true;
			return;
		}
	} else {
		for (int i = index; i < 9; i++) {
			list.push_back(arr[i]);
			solve(list, i + 1);
			list.pop_back();
		}
	}

}
int main() {	
	for (int i = 0; i < 9; i++) std::cin >> arr[i];
	List list;
	solve(list, 0);
	return 0;
}