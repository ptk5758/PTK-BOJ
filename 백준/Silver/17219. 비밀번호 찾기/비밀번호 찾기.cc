#include <iostream>
#include <string>
#include <map>

int main() {
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n, m;
	std::cin >> n >> m;
	int i = n;
	std::map<std::string, std::string> map;
	while (i--) {
		std::string str1, str2;
		std::cin >> str1 >> str2;
		map.insert(std::make_pair(str1, str2));
	}
	i = m;	
	while (i--) {
		std::string str1;
		std::cin >> str1;
		std::cout << map[str1] << "\n";
	}
	return 0;
}