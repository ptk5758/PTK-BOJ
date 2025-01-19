#include <iostream>
#include <string>

int main() {
    int t; std::cin >> t;
    while (t--)
    {
        int n, m; std::cin >> n >> m;
        int result = 0;
        for (int i=n; i<=m; i++) {
            std::string str = std::to_string(i);
            for (int j=0; j<str.size(); j++)
            {
                if (str[j] == '0')
                    result++;
            }            
        }
        std::cout << result << "\n";
    }
    return 0;
}