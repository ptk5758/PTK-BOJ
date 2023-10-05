#include <iostream> // input output stream

int main()
{   
	int n, m;
	std::cin >> n >> m;
	int** arr = new int *[m];
	for (int i = 0; i < m; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			int value;
			std::cin >> value;
			arr[i][j] = value;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int value;
			std::cin >> value;
			arr[i][j] += value;
		}
	}
	for (int i = 0; i < m; i++) {		
		for (int j = 0; j < n; j++) {
			std::cout << arr[i][j];
			if (j == n - 1) std::cout << "\n";
			else std::cout << " ";
		}		
	}
	

	
}
