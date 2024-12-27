#include <iostream>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n; std::cin >> n;
	int arr[100001] = {0, };
	int index = 0;
	while (n--)
	{
		std::string str; std::cin >> str;
		if (str == "push") {
			int value; std::cin >> value;
			arr[index++] = value;
		} else if (str == "pop") {
			std::cout << (index > 0 ? arr[--index] : -1) << "\n";
		} else if (str == "size") {
			std::cout << index << "\n";
		} else if (str == "empty") {
			std::cout << (index == 0 ? 1 : 0) << "\n";
		} else if (str == "top") {
			std::cout << (index > 0 ? arr[index - 1] : -1) << "\n";
		}
	}
	return 0;
}