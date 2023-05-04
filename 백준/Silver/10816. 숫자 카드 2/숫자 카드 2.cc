#include <iostream>
#include <map>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N, M, i, value;
	std::map<int, int> map;	
	std::cin >> N;
	for (i = 0; i < N; i++) {		
		std::cin >> value;
		if (map[value]) map[value]++;
		else map[value] = 1;
	}

	std::cin >> M;
	for (i = 0; i < M; i++) {
		std::cin >> value;
		std::cout << map[value] << " ";		
	}
}