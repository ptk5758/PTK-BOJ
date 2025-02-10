#include <iostream>
#include <algorithm>

typedef std::pair<int, int> Pair;
int main() {
	Pair arr[8];
	for (int i = 0; i < 8; i++)
	{
		arr[i].first = i + 1;
		std::cin >> arr[i].second;
	}
	std::sort(arr, arr + 8, [](Pair &a, Pair &b) {
		return a.second > b.second;
	});
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += arr[i].second;
	}
	std::cout << sum << "\n";
	std::sort(arr, arr + 5, [](Pair& a, Pair& b) {
		return a.first < b.first;
	});
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i].first << " ";
	}
	std::cout << "\n";
}