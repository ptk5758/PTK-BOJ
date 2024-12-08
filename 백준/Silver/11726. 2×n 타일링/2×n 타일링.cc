#include <iostream>
#include <vector>
typedef std::vector<int> Vector;
int main()
{
	int n; std::cin >> n;
	Vector d(n + 1);
	d[0] = 0;
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		d[i] = (d[i - 2] + d[i - 1]) % 10007;
	}
	std::cout << d[n] << "\n";
	return 0;
}