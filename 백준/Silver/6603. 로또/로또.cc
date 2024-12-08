#include <iostream>
#include <vector>
typedef std::vector<int> List;
void Solution(int n, int start, List &actived, List &list)
{
	if (actived.size() == 6)
	{
		for (int value : actived)
		{
			std::cout << list[value] << " ";
		}
		std::cout << "\n";
	}
	else
	{
		for (int i = start; i < list.size(); i++)
		{
			actived.push_back(i);
			Solution(n, i + 1, actived, list);
			actived.pop_back();
		}
	}
}
void Solve(int n)
{
	List list(n), actived;

	for (int i = 0; i < n; i++) {
		int value; std::cin >> value;
		list[i] = value;
	}

	Solution(n, 0, actived, list);
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	while (true) {		
		int n; std::cin >> n;
		if (n == 0) break;
		Solve(n);
		std::cout << "\n";
	}
	return 0;
}