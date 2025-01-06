#include <iostream>
#include <vector>

int main()
{
	int a, b; std::cin >> a >> b;
	std::vector<int> v;
	int i = 1;
	while (b >= v.size())
	{
		for (int j = 0; j < i; j++)
		{
			v.push_back(i);
		}
		i++;
	}
	int result = 0;
	for (int i = a - 1; i < b; i++)
	{
		result += v[i];
	}
	std::cout << result << "\n";
	return 0;
}