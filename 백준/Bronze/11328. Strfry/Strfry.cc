#include <iostream>
#include <string>
bool Solve()
{	
	std::string a, b; std::cin >> a >> b;
	int aArr[26] = { 0, };
	int bArr[26] = { 0, };
	for (int i = 0; i < a.size(); i++)
	{
		int aIndex = a[i] - 'a';
		int bIndex = b[i] - 'a';
		aArr[aIndex]++;
		bArr[bIndex]++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (aArr[i] != bArr[i]) return false;
	}
	return true;
}
int main()
{
	int n; std::cin >> n;
	while (n--)
	{
		if (Solve()) 
		{
			std::cout << "Possible" << "\n";
		}
		else 
		{
			std::cout << "Impossible" << "\n";
		}
	}
	return 0;
}