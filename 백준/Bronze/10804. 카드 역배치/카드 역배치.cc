#include <iostream>

int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int n = 10;
	while (n--) {
		int l, r; std::cin >> l >> r;
		l--;
		r--;
		while (l < r) {
			int temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
			l++;
			r--;
		}
	}
	for (int i = 0; i < 20; i++) {
		std::cout << arr[i] << " ";
	}
	return 0;
}