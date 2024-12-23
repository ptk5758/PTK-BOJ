#include <iostream>
#include <vector>
#include <algorithm>

using List = std::vector<char>;

void Solution(int index, int k, List &list, List &nums, int mo, int ja)
{
	if (list.size() == k)
	{
		if (mo <= 0 || ja < 2) return;
		for (char &value : list)
		{
			std::cout << value;
		}
		std::cout << "\n";
		return;
	}

	for (int i=index; i<nums.size(); i++)
	{
		char num = nums[i];
		int m = 0, j = 0;		
		if (num == 'a' || num == 'e' || num == 'i' || num == 'o' || num == 'u') m++;
		else j++;
		list.push_back(num);
		Solution(i + 1, k, list, nums, mo + m, ja + j);
		list.pop_back();
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n, m; std::cin >> n >> m;
	List nums(m), t;
	for (int i=0; i<m; i++) std::cin >> nums[i];
	std::sort(nums.begin(), nums.end());
	Solution(0, n, t, nums, 0, 0);
	return 0;
}