#include <iostream>
#include <stack>

template <typename T>
using Stack = std::stack<T>;
void Solve()
{
	int n; std::cin >> n;
	Stack<int> s;
	for (int i = 0; i < n; i++)
	{
		int value; std::cin >> value;
		s.push(value);
	}
	long long result = 0;
	int top = s.top(); s.pop();
	while (!s.empty())
	{
		int value = s.top(); s.pop();
		if (top > value)
		{
			result += top - value;
		}
		else
		{
			top = value;
		}
	}
	std::cout << result << "\n";
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t; std::cin >> t;
	while (t--) Solve();
	return 0;
}