#include <iostream>
#include <algorithm>
bool Solution(int* arr, int find, int start, int mid, int end) {

	if (start > end) return false;
	if (find == arr[mid]) return true;
	else if (find > arr[mid]) start = mid + 1;
	else end = mid - 1;	
	return Solution(arr, find, start, (start+end)/2, end);	
}
int main() {	
	std::ios_base::sync_with_stdio(0); 
	std::cin.tie(0);
	int N, C, userStream;
	std::cin >> N;	
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		std::cin >> userStream;
		arr[i] = userStream;
	}
	std::sort(arr, arr+N);
	std::cin >> C;
	for (int i = 0; i < C; i++) {
		std::cin >> userStream;		
		std::cout << Solution(arr, userStream, 0, (0 + N - 1) / 2, N - 1) << "\n";
	}
	return 0;
}