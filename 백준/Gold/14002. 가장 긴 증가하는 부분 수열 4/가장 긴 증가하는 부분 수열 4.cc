#include <iostream>
#include <algorithm>
#include <stack>

template <typename T>
using Stack = std::stack<T>;

int arr[1001] = { 0, };
int d[1001] = { 0, 1 };
int p[1001] = { 0, };
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n; std::cin >> n;
	for (int i = 1; i <= n; i++) std::cin >> arr[i];

	int max = 1;
	int maxIndex = 1;
	for (int i = 2; i <= n; i++)
	{
		int count = 0;
		int index = 0;
		for (int j = i - 1; j > 0; j--)
		{
			if (arr[i] > arr[j])
			{
				if (count < d[j])
				{
					count = d[j];
					index = j;
;				}
			}
		}
		p[i] = index;
		d[i] = count + 1;
		if (max < d[i])
		{
			max = d[i];
			maxIndex = i;
		}
	}
	Stack<int> s;
	int current = p[maxIndex];
	s.push(arr[maxIndex]);
	while (current != 0)
	{
		s.push(arr[current]);
		current = p[current];
	}

	std::cout << max << "\n";
	while (!s.empty())
	{
		int value = s.top(); s.pop();
		std::cout << value << " ";
	}
	std::cout << "\n";
	return 0;
}