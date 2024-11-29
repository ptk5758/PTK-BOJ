#include <iostream>
int main()
{
	int h, m, s, v;
	std::cin >> h >> m >> s >> v;
	int t = 0;
	t += h * 3600;
	t += m * 60;
	t += s;
	t += v;
	t %= 3600 * 24;
	int H = t / 3600;
	t %= 3600;
	int M = t / 60;
	t %= 60;
	int S = t;
	std::cout << H << " " << M << " " << S << "\n";


}