#include <iostream>
int arr[41];
int a = 0, b = 0;
int fib(int n) {
    
    if (n == 1 || n == 2) {
        a++;
        return 1;
    } else {
        return (fib(n - 1) + fib(n - 2));
    }
    
}
int fibonacci(int n) {
    if (n == 1 || n == 2) return 1;
    if (arr[n]) return arr[n];
    b++;
    return arr[n] = fibonacci(n-2) + fibonacci(n-1);
}
int main() {
    int value;
    std::cin >> value;
    fib(value);
    fibonacci(value);
    std::cout << a << " " << b;
    return 0;
}
