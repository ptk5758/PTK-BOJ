#include <iostream>

int main() {
    int n; std::cin >> n;
    
    int sum = 0;
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            sum += i+j;
        }
    }
    
    std::cout << sum;
    
    return 0;
}