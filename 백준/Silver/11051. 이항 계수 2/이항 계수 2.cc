#include <iostream>
long long arr[1000];
long long factorial(int a) {
    if (a == 0) return 1;
    if (a == 1) return 1;
    if (arr[a]) return arr[a];
    return arr[a] = (a % 10007) * (factorial(a-1) % 10007) % 10007;
}
int pow(int N, int K) {
    if (K == 0) return 1;
    if (K == 1) return N % 10007;
    int value = pow(N, K / 2) % 10007;
    if (K % 2 == 0) {
        return ((value % 10007) * (value % 10007)) % 10007;
    } else {
        return (value * value % 10007) * (N % 10007) % 10007;
    }
    
    
}
int solve (int N, int K) {
    if (K == 0 || N == K) return 1;
    int child = factorial(N) % 10007;
    int parent = (factorial(K) * factorial(N - K)) % 10007;
    return child * pow(parent, 10005) % 10007;
}
int main () {
    int N, K;
    std::cin >> N >> K;
    std::cout << solve(N, K);
//    std::cout << pow(N, K);
}
