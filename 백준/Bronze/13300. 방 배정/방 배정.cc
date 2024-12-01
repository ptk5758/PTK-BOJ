#include <iostream>

int main()
{
	int arr[2][6] = {0,};
	int n, k; std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int gender, value; std::cin >> gender >> value;
		arr[gender][value - 1]++;
	}	
	int result = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			/*std::cout << arr[i][j] << " ";*/
			result += arr[i][j] / k;
			if (arr[i][j] % k > 0) result++;
		}
		/*std::cout << "\n";*/
	}
	std::cout << result << "\n";
	return 0;
}