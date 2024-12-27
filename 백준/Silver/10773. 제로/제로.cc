#include <iostream>
#include <string>
#include <stack>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n; std::cin >> n;
	std::stack<int> s;
	while (n--)
	{
		int value; std::cin >> value;
		if (value == 0) {
			s.pop();
		} else {
			s.push(value);
		}
	}
	int result = 0;
	while (!s.empty()) {
		result += s.top(); s.pop();
	}	
	std::cout << result << "\n";
	return 0;
}