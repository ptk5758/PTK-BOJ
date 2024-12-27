#include <iostream>
#include <stack>

using Pair = std::pair<int, int>;
using Stack = std::stack<Pair>;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	int n; std::cin >> n;
	Stack s;	
	for (int i=1; i<=n; i++) {
		int value; std::cin >> value;
		if (s.empty()) {
			s.push({i, value});
			std::cout << 0 << " ";
		} else {
			while (!s.empty() && s.top().second < value) {
				s.pop();
			}
			std::cout << (s.empty() ? 0 : s.top().first) << " ";
			s.push({i, value});
		}
	}
	std::cout << "\n";
	return 0;
}