#include <iostream>
#include <cmath>

int main() {	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N, value, index = 0;
	std::cin >> N;
	int* arr = new int[N];
	int i = N;
	// 1 -1 2 -2
	while (i--) {
		std::cin >> value;
		if (value) {
			arr[index] = value;
			int child = index++;
			while (child != 0) {
				int root = (child - 1) / 2;
				// 스왑을 해야하는 조건 절대값이 더 작으면 || 절대값은 같은데 값이 다른경우
				if (std::abs(arr[root]) > std::abs(arr[child]) || (std::abs(arr[root]) == std::abs(arr[child]) && arr[root] > arr[child]) ) {
					int temp = arr[root];
					arr[root] = arr[child];
					arr[child] = temp;
				}
				child = root;
			}
		} else {
			// for (int i = 0; i < index; i++) std::cout << arr[i];
			if (index) {
				std::cout << arr[0] << "\n";
				arr[0] = arr[--index];
				int root = 0;
				while (root < index) {
					int child = root * 2 + 1;

					if (child < index) {
						if (std::abs(arr[child]) > std::abs(arr[child+1]) || (std::abs(arr[child]) == std::abs(arr[child+1]) && arr[child] > arr[child+1])) {
							child++;
						}
					}
					if (child < index) {
						if (std::abs(arr[root]) > std::abs(arr[child]) || (std::abs(arr[root]) == std::abs(arr[child]) && arr[root] > arr[child])) {
							int temp = arr[root];
							arr[root] = arr[child];
							arr[child] = temp;
						}
					}

					root = child;
				}
			} else std::cout << 0 << "\n";
		}
	}


}