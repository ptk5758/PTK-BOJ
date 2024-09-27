#include <iostream>

int main() {
    int N = 7, min = -1, sum = 0;
    for (int i=0; i<N; i++) {
        int value; std::cin >> value;
        if (value % 2 == 1) {
            sum += value;
            if (min == -1) {
                min = value;
            } else {
                if (min > value) min = value;
            }
        }
    }
    if (sum != 0) {
        std::cout << sum << "\n";
    }
    std::cout << min << "\n";
    return 0;
}
