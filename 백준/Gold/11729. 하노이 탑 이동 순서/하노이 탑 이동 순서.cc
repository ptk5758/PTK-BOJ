#include <iostream>
void func(int s, int e, int n)
{
	if (n == 1) {
		std::cout << s << " " << e << "\n";
		return;
	}	
	func(s, 6-s-e, n - 1);
	std::cout << s << " " << e << "\n";
	func(6-s-e, e, n - 1);
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	int n; std::cin >> n;
	std::cout << (1<<n) - 1 <<"\n";
	func(1, 3, n);
	return 0;
}