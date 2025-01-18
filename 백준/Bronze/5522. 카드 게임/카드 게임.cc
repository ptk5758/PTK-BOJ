#include <iostream>

int main()
{	
	long long total = 0;
	for (int i = 0; i < 5; i++)
	{
		long long n; std::cin >> n;
		total += n;
	}
	std::cout << total << "\n";
}