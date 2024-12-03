#include <iostream>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n; std::cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) std::cin >> arr[i];
	std::sort(arr, arr + n);
	int m; std::cin >> m;
	while (m--)
	{
		int value; std::cin >> value;
		int start = 0;
		int end = n;
		bool flag = false;
		while (start < end)
		{
			int mid = start + (end - start) / 2;
			if (arr[mid] == value)
			{
				flag = 1;
				break;
			}
			else if (arr[mid] > value)
			{
				end = mid;
			}
			else if (arr[mid] < value)
			{
				start = mid + 1;
			}
		}
		std::cout << flag << " ";
	}

	return 0;
}