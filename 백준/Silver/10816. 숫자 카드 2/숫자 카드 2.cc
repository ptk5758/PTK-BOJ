#include <iostream>
#include <algorithm>
#include <vector>
#define MIN -10000000
#define MAX 10000000
typedef std::vector<int> List;
int lowerBound(List &list, int value)
{
	int start = 0;
	int end = list.size();
	while (start < end)
	{
		int mid = start + (end - start) / 2;
		if (list[mid] < value)
		{
			start = mid + 1;
		}
		else
		{
			end = mid;
		}
	}	
	return start;
}
int upperBound(List &list, int value)
{
	int start = 0;
	int end = list.size();
	while (start < end)
	{
		int mid = start + (end - start) / 2;
		if (list[mid] <= value)
		{
			start = mid + 1;
		}
		else
		{
			end = mid;
		}
	}	
	return start;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n; std::cin >> n;
	List list;	
	for (int i = 0; i < n; i++)
	{
		int value; std::cin >> value;
		list.push_back(value);
	}
	std::sort(list.begin(), list.end());
	int m; std::cin >> m;
	while (m--)
	{
		int value; std::cin >> value;
		std::cout << upperBound(list, value) - lowerBound(list, value) << " ";
	}
	
	return 0;
}