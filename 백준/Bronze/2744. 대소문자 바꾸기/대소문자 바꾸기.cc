#include <iostream>
#include <string>
#include <locale>
int main() {
	std::string str1;
	std::cin >> str1;
	char* line = new char[str1.length() + 1];
	for (int i = 0; i < str1.length(); i++)
	{
		if ('a' <= str1[i] && 'z' >= str1[i]) {
			line[i] = std::toupper(str1[i]);
		} else {
			line[i] = std::tolower(str1[i]);
		}
	}
	for (int i = 0; i < str1.length(); i++)
	{
		std::cout << line[i];
	}
	return 0;
}