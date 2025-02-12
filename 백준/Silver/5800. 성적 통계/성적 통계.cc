#include <iostream>
#include <algorithm>

int main() {
	int n; std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k; std::cin >> k;
		int* arr = new int[k];
		int x = -1;
		for (int j = 0; j < k; j++)
		{
			std::cin >> arr[j];
			
		}
		std::sort(arr, arr + k);
		for (int j = 1; j < k; j++)
		{			
			x = std::max(x, std::abs(arr[j] - arr[j - 1]));			
		}
		std::cout << "Class " << i + 1 << "\n";
		std::cout << "Max " << arr[k-1] << ", " << "Min " << arr[0] << ", Largest gap " << x << "\n";
	}
	return 0;
}