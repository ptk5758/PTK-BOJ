#include <iostream>
#define Quarter 25
#define Dime 10
#define Nickel 5
#define Penny 1
void solve(int cost) {
    int arr[] = {Quarter, Dime, Nickel, Penny};
    int result[4] = {0,};
    int index = 0;
    while (cost > 0) {
        result[index] = cost / arr[index];
        cost %= arr[index++];
    }
    for (int i=0; i<4; i++) {
        std::cout << result[i] << " ";
    }
}
int main() {
    int t; std::cin >> t;
    while (t--) {
        int value; std::cin >> value;
        solve(value);
        std::cout << "\n";
    }
}
