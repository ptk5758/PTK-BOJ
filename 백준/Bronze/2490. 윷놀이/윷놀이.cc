#include <iostream>
#include <map>

int main() {


	// 등의 갯수
	std::map<int, char> m = {
		{0, 'D'},
		{1, 'C'},
		{2, 'B'},
		{3, 'A'},
		{4, 'E'}
	};

	for (int i = 0; i < 3; i++) {
		int count = 0;
		for (int j = 0; j < 4; j++) {
			bool t; std::cin >> t;			
			if (t) count++;			
		}	
		std::cout << m[count] << "\n";
	}

	return 0;
}