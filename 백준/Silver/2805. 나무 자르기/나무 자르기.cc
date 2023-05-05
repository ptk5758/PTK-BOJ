#include <iostream>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);	
	long long N, M, max = -1;
	std::cin >> N >> M;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) std::cin >> arr[i];
	std::sort(arr, arr + N);
	// for (int i = 0; i < N; i++) std::cout << arr[i] << " "; // 출력
	long long start, mid, end, sum;
	start = 0;
	end = arr[N - 1];
	while (start <= end) {
		sum = 0;
		mid = (start + end) / 2;
		for (int i = 0; i < N; i++) {
			if (arr[i] - mid > 0) sum += arr[i] - mid;
		}
		if (sum >= M) {
			start = mid + 1;
			if (mid > max) max = mid;
		} else {
			end = mid - 1;
		}
	}
	std::cout << max;
}