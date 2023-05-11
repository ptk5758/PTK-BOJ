#include <iostream>
#include <algorithm>

int main() {	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N, value, index = 0;
	std::cin >> N;
	int* arr = new int[N];
	int i = N;
	while (i--) {
		std::cin >> value;
		if (value) {
			arr[index] = value; // 마지막 인덱스에 삽입
			int child = index++;
			while (child != 0) {
				int root = (child - 1) / 2;
				if (arr[root] < arr[child]) {
					int temp = arr[root];
					arr[root] = arr[child];
					arr[child] = temp;
				}
				child = root;
			}
		} else {
			if (index) {
				std::cout << arr[0] << "\n";
				arr[0] = arr[--index]; // index  2
				int root = 0;
				while (root < index) {
					int child = root * 2 + 1;
					if (child < index && arr[child] < arr[child + 1]  ) child++;
					if (child < index && arr[child] > arr[root] ) {
						int temp = arr[child];
						arr[child] = arr[root];
						arr[root] = temp;
					}
					root = child;
				}
				
			} else {
				std::cout << 0 << "\n";
			}
		}
	}


}