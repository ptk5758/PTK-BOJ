#include <iostream>

int main() {
	int arr[] = { 0,0,0,0,0,0,0,0,0,0, };
	char line[8]; std::cin >> line;
	int index = 0;
	while (line[index] != '\0') {
		int value = line[index] - '0';
		if (value == 6 || value == 9) {
			if (arr[6] <= arr[9]) {
				arr[6]++;
			} else {
				arr[9]++;
			}
		} else {
			arr[value]++;
		}		
		index++;
	}	
	int max = 0;
	for (int i = 0; i < 10; i++) {		
		if (arr[i] > max) max = arr[i];
	}
	std::cout << max << "\n";
	return 0;
}