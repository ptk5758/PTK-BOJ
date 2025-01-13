#include <iostream>
#include <algorithm>

int main()
{
	int n; std::cin >> n;	
	while (n--)
	{
		int arr[5];
		for (int i = 0; i < 5; i++) std::cin >> arr[i];
		std::sort(arr, arr + 5);
		if (arr[3] - arr[1] >= 4) {
			std::cout << "KIN" << "\n";
		} else {
			int sum = 0;
			for (int j = 1; j < 4; j++) sum += arr[j];
			std::cout << sum << "\n";
		}
	}
}