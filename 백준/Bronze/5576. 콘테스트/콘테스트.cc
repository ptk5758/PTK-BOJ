#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int value, a=0, b=0;
	std::vector<int> w, k;
	for (int i = 0; i < 10; i++)
	{
		std::cin >> value;
		w.push_back(value);
	}	
	for (int i = 0; i < 10; i++)
	{
		std::cin >> value;
		k.push_back(value);
	}
	std::sort(w.begin(), w.end());
	std::sort(k.begin(), k.end());
	for (int i = 7; i < 10; i++) {
		a += w[i];
		b += k[i];
	}
	std::cout << a << " " << b << "\n";
	return 0;
}