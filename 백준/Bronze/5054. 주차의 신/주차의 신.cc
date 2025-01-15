#include <iostream>
#include <algorithm>

int main()
{	
	int t; std::cin >> t;
	while (t--)
	{
		int n; std::cin >> n;
		int* arr = new int[n];
		for (int i = 0; i < n; i++) std::cin >> arr[i];
		std::sort(arr, arr + n);
		std::cout << ((arr[n - 1] - arr[0]) * 2) << "\n";
	}
}