#include <iostream>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N, C, max = -1;
	std::cin >> N >> C;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) std::cin >> arr[i];
	std::sort(arr, arr + N);
	int start, mid, end, count, last;
	start = 0;
	end = arr[N - 1];
	while (start <= end) {
		count = 1; // 설치한 공유기의 갯수
		mid = (start + end) / 2; // 최대 거리
		last = 0;
		for (int i = 1; i < N; i++) {
			if (arr[i] - arr[last] >= mid) {
				count++;
				last = i;
			}
		}


		if (count >= C) { // 요구한 것 보다 공유기를 설치를 더했을때
			start = mid + 1;
			if (mid > max) max = mid;
		} else {
			end = mid - 1;
		}
		// std::cout << "MID : " << mid << " Count : " << count <<  "\n";

	}
	std::cout << max;
}