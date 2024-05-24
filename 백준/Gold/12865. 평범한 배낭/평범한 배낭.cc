#include <iostream>

int main() {
	// 초기화
	int n, m;
	std::cin >> n >> m;
	m++;
	n++;
	std::pair<int, int>* ariticles = new std::pair<int, int>[n];
	ariticles[0] = std::make_pair(0, 0);
	for (int i = 0; i < n-1; i++) {
		int weight, price;
		std::cin >> weight >> price;
		ariticles[i+1] = std::make_pair(weight, price);
	}
	

	int** arr = new int * [m];
	for (int i = 0; i < m; i++) {
		arr[i] = new int [n] {0,};
	}

	// Service
	for (int i =  1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			std::pair<int, int> product = ariticles[j];
			if (i < product.first) { // 무게 초과
				arr[i][j] = arr[i][j - 1];
			} else {
				if (arr[i-product.first][j-1] + product.second > arr[i][j-1]) { // 넣을때
					arr[i][j] = arr[i - product.first][j - 1] + product.second;
				} else {
					arr[i][j] = arr[i][j - 1];
				}

			}
		}
	}

	std::cout << arr[m - 1][n-1];


	// 할당 해제
	for (int i = 0; i < m; i++) {
		delete arr[i];
	}
	delete [] arr;
	delete [] ariticles;
	return 0;
}