#include <iostream>
int arr[41] = { 0, };
int fibonacci(int value)
{
	if (value < 0) return 1;
	if (value == 0) return 0;
	if (value == 1) return 1;	
	if (arr[value] != 0) return arr[value];
	arr[value] = fibonacci(value - 2) + fibonacci(value - 1);
	return arr[value];
}
int main()
{
	int n;
	std::cin >> n;
	while (n--) {
		int value;
		std::cin >> value;
		std::cout << fibonacci(value-1) << " " << fibonacci(value) << "\n";
	}
	return 0;
}