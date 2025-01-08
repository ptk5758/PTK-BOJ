#include <iostream>

int main()
{
    int n; std::cin >> n;
    int result = 0;
    for (int i=0; i<n; i++)
    {
        int value, count; std::cin >> value >> count;        		
        result += count % value;
    }
    std::cout << result << "\n";
    return 0;
}