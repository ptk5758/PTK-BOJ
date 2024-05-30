#include <iostream>
long long arr[11];
long long fectorial(int a) {
    if (a == 0) return 1;
    if (a == 1) return 1;
    if (arr[a]) return arr[a];
    return arr[a] = a * fectorial(a-1);
}
double solve (int N, int K) {
    return fectorial(N) / (fectorial(N-K) * fectorial(K));
}
int main () {
    int N, K;
    std::cin >> N >> K;
    std::cout << solve(N, K);
}
