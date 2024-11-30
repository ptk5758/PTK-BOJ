#include <iostream>
#include <string>
int main()
{
	int n;
	
	std::cin >> n;
	std::string str = std::to_string(n);

	int arr[10] = { 0, };
	for (int i = 0; i < str.size(); i++) {
		int value = str[i] - '0';
		if (value == 6) {
			if (arr[6] > arr[9]) {
				arr[9]++;
			}
			else {
				arr[6]++;
			}
		} else if (value == 9) {
			if (arr[9] > arr[6]) {
				arr[6]++;
			}
			else {
				arr[9]++;
			}
		} else {
			arr[value]++;
		}
		
	}
	int max = 0;
	for (int i = 0; i < 10; i++) {
		if (max < arr[i]) max = arr[i];
	}
	std::cout << max << "\n";
}