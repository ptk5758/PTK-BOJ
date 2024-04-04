#include <iostream>
#include <set>
#include <string>
int main() {
	int n, s;
	std::cin >> n >> s;
	int i = n;
	std::set<std::string> set;
	int answer = 0;
	while (i--) {
		std::string str;
		std::cin >> str;
		set.insert(str);
	}
	i = s;

	while (i--) {
		std::string str;
		std::cin >> str;
		if (set.count(str) > 0) answer++;
	}
	std::cout << answer;
	return 0;
	
}