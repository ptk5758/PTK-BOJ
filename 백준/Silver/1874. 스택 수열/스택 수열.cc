#include <iostream>
#include <stack>
#include <vector>

template <typename T>
using Stack = std::stack<T>;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	Stack<int> s;
	int n; std::cin >> n;
	Stack<int> s1, s2;
	std::vector<char> result;
	s1.push(0);
	for (int i=n; i>0; i--) s2.push(i);
	while (n--)
	{
		int value; std::cin >> value;
		if (s1.top() > value) {
			s1.pop();
			result.push_back('-');
		} else if (s1.top() < value) {
			while (s1.top() < value) {
				if (s2.empty()) {
					std::cout << "NO" << "\n";
					return 0;
				}
				s1.push(s2.top()); s2.pop();
				result.push_back('+');
			}
			if (s1.top() > value) {
				std::cout << "NO" << "\n";
				return 0;
			}
		}
		if (s1.top() == value) {
			s1.pop();
			result.push_back('-');
		}
	}
	for (char &c : result) {
		std::cout << c << "\n";
	}
	return 0;
}