#include <iostream>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int K, N, count;
	std::cin >> K >> N;
	long long* arr = new long long[K];
	for (int i = 0; i < K; i++) std::cin >> arr[i];
	std::sort(arr, arr + K);
	long long start, mid, end, max = -1;
	start = 0;
	end = arr[K - 1];
	while (start <= end) {
		count = 0;
		mid = (start + end) / 2;
		if (mid == 0) mid = 1;
		for (int i = 0; i < K; i++) {
			if (arr[i] >= mid) count += arr[i] / mid;
		}
		if (count >= N) {
			start = mid + 1;
			if (mid > max) max = mid;
		} else {
			end = mid - 1;
		}
	}
	std::cout << max;
}