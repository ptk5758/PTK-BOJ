#include <iostream>
#include <algorithm>

int arr[1001] = { 0, };
int d[1001] = { 0, };

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n; std::cin >> n;

	for (int i = 1; i <= n; i++) std::cin >> arr[i];

	d[1] = arr[1];
	int result = arr[1];
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
		d[i] = max + arr[i];
		result = std::max(result, d[i]);
	}
	std::cout << result << "\n";
	return 0;
}