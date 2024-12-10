#include <iostream>
#include <algorithm>

int arr[1001] = { 0, };
int d[1001] = { 0, };
int main()
{
	int n; std::cin >> n;
	for (int i = 1; i <= n; i++) std::cin >> arr[i];
	if (n == 1)
	{
		std::cout << 1 << "\n";
		return 0;
	}
	d[1] = 1;
	int result = 0;
	for (int i = 2; i <= n; i++)
	{
		int max = 0;
		for (int j = i - 1; j >= 1; j--)
		{
			if (arr[i] > arr[j])
			{
				max = std::max(max, d[j]);
			}
		}
		d[i] = max + 1;
		result = std::max(result, d[i]);
	}
	std::cout << result << "\n";	
	return 0;
}