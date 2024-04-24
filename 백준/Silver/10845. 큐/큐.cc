#include <iostream>
#include <string>
#include <vector>
int main() {
	int n;
	std::cin >> n;
	int arr[100001];
	int front = 0;
	int rear = 0;
	for (int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;
		if (str == "push") {
			int value;
			std::cin >> value;
			arr[rear++] = value;
		} else if (str == "pop") {
			if (front == rear) {
				std::cout << -1 << "\n";
			} else {
				std::cout << arr[front++] << "\n";
			}
		} else if (str == "size") {
			std::cout << (rear - front) << "\n";
		} else if (str == "empty") {
			std::cout << (rear == front ? 1 : 0) << "\n";
		} else if (str == "front") {
			if (front == rear) {
				std::cout << -1 << "\n";
			} else {
				std::cout << arr[front] << "\n";
			}
		} else {
			if (front == rear) {
				std::cout << -1 << "\n";
			}
			else {
				std::cout << arr[rear-1] << "\n";
			}
		}
	}
	return 0;
}