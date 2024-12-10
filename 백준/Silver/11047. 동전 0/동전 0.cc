#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, k; std::cin >> n >> k;
	int arr[11], result = 0;
	for (int i = 0; i < n; i++) std::cin >> arr[i];
	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] <= k)
		{
			result += k / arr[i];
			k = k % arr[i];
		}
	}
	std::cout << result << "\n";

	return 0;
}