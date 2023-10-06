#include <iostream>
int main() {
    int max = -1;
    int x = 0;
    int y = 0;
    int index = 0;
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            int value;
            std::cin >> value;
            if (value >= max) {
                max = value;
                x = j;
                y = i;
            }
            index++;
        }
    }
    std::cout << max << "\n" << y+1 << "  "<< x+1;
    
}
