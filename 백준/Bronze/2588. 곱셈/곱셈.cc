#include <iostream>

int main()
{	
	int a,b;
	std::cin >> a >> b;

	int x = (b / 100);
	int y = (b - (x * 100)) / 10;
	int z = (b - ((x * 100) + (y * 10))) / 1;

	std::cout << a * z << "\n";
	std::cout << a * y << "\n";
	std::cout << a * x << "\n";		
	std::cout << a * b << "\n";
}
