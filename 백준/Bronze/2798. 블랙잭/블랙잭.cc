#include <iostream>

int cards[101] = { 0, };

int SumCardValue(int i, int j, int k) {
	return cards[i] + cards[j] + cards[k];
}
int main() {
	int n, targetValue, num, index=0;	
	std::cin >> n >> targetValue;
	int a = n;
	while (a--) {
		std::cin >> num;
		cards[index++] = num;
	}
	int maxValue = 0;

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				int cardValue = SumCardValue(i, j, k);
				if (targetValue >= cardValue && maxValue < cardValue) {
					maxValue = cardValue;
				}
			}
		}
	}

	std::cout << maxValue << "\n";




}