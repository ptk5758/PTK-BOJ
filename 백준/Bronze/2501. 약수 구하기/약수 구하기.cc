#include <iostream>
int main()
{
	int n, k; std::cin >> n >> k;	
	int i = 1, index = 1;
	int arr[10005] = { 0, };
	while (i <= n + 1)
	{
		if (n % i == 0)
		{
			arr[index++] = i;
		}
		i++;
	}
	std::cout << arr[k] << "\n";
	return 0;
}