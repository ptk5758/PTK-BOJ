#include <iostream>
#include <string>
#include <algorithm>

int main() 
{
	std::string str; std::cin >> str;
	int* arr = new int[str.size()];
	for (int i = 0; i < str.size(); i++)
	{
		int value = str[i] - '0';
		*(arr + i) = value;
	}	
	std::sort(arr, arr + str.size(), [](int a, int b) { return a > b;});
	for (int i = 0; i < str.size(); i++)
	{
		std::cout << *(arr + i);
	}
	std::cout << "\n";
	return 0;	
}