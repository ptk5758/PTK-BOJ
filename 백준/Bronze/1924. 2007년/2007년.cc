#include <iostream>
#include <vector>
#include <string>
int main() {
	int x, y;
	std::cin >> x >> y;
	//            1  2   3     4   5   6   7   8   9    10  11 12
	int arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int sum = y;
	std::vector<std::string> word = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	for (int i = 0; i < x; i++) {
		sum += arr[i];
	}
	std::cout << word[sum % 7] << "\n";
	return 0;
}