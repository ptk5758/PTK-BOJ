#include <iostream>
void fn(int *cnt, int sum, int target) {
    if (sum == target) {
        *cnt = *cnt + 1;
        return;
    } else if (sum > target) {
        return;
    } else {
        for (int i=1; i<4; i++) {
            fn(cnt, sum + i, target);
        }
    }
}
int main() {
    int n;
    std::cin >> n;
    while (n--) {
        int value;
        int cnt = 0;
        std::cin >> value;
        for (int i=1; i<4; i++) {
            fn(&cnt, i, value);
        }
        std::cout << cnt << "\n";
    }
}
