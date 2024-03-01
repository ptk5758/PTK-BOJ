#include <iostream>
int min = 100000000;
void dfs(int count, int now, int target) {
    if (min < count) return;
    if (now != target) {
        if (now % 3 == 0) dfs(count + 1, now / 3, 1);
        if (now % 2 == 0) dfs(count + 1, now / 2, 1);
        dfs(count + 1, now - 1, 1);
    } else {
        if (min > count) min = count;
    }
}
int main() {
    int value;
    std::cin >> value;
    dfs(0, value, 1);
    std::cout << min;
    return 0;
}
