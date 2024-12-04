#include <iostream>
#include <algorithm>
#define MAX 1000000001
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n; std::cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) std::cin >> arr[i];
	std::sort(arr, arr + n);
	int start = 0;
	int end = n - 1;
	std::pair<int, int> result(MAX, MAX);
	while (start < end)
	{
		int cal = arr[start] + arr[end];
		if (std::abs(cal) < std::abs(result.first + result.second))
		{
			result.first = arr[start];
			result.second = arr[end];
		}
			
		if (cal == 0) {
			result.first = arr[start];
			result.second = arr[end];
			break;
		} else if (cal > 0) {
			end--;
		} else {
			start++;
		}
	}
	std::cout << result.first << " " << result.second << "\n";



	return 0;
}