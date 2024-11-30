#include <iostream>
#include <algorithm>
int main()
{
	int n; std::cin >> n;
	int* arr = new int[n + 1];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	int x; std::cin >> x;
	int result = 0;
	std::sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (arr[i] >= x) break;
		for (int j = i + 1; j < n; j++) {
			int value = arr[i] + arr[j];
			if (value == x) {
				/*std::cout << arr[i] << "," << arr[j] << "\n";*/
				result++;
			} else if (value > x) {
				break;
			}
		}
	}
	std::cout << result << "\n";
	return 0;
}