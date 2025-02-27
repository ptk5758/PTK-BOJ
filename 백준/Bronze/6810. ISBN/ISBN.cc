#include <iostream>
#include <string>
int main() {
	std::string str = "9780921418", temp;
	for (int i = 0; i < 3; i++) {
		std::cin >> temp;
		str += temp;
	}
	long long result = 0;
	for (int i = 0; i < str.size(); i++)
	{
		long long value = str[i] - '0';
		if (i % 2 == 0)
		{
			result += value * 1;
		}
		else
		{
			result += value * 3;
		}
	}
	std::cout << "The 1-3-sum is " << result << "\n";
	return 0;
}