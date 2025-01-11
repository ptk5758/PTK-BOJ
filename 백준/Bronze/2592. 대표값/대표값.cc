#include <iostream>

int main()
{
	int arr[1001] = { 0, };
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		int value; std::cin >> value;
		sum += value;
		arr[value]++;
	}
	int average = sum / 10;
	int max = 0;
	int index = 0;
	for (int i = 10; i <= 1000; i++)
	{
		if (max < arr[i]) {
			max = arr[i];
			index = i;
		}
	}
	std::cout << average << "\n";
	std::cout << index << "\n";

}