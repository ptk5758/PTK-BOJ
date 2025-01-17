#include <iostream>
#include <algorithm>

int main()
{	
	int arr[5];
	for (int i = 0; i < 5; i++) std::cin >> arr[i];
	std::sort(arr, arr + 3);
	std::sort(arr + 3, arr + 5);
	std::cout << arr[0] + arr[3] - 50 << "\n";
}