#include <iostream>
char board[50][50];
int solve(int y, int x) {
    int cnt = 0;
    for (int i=y; i<y+8; i++) {
        for (int j=x; j<x+8; j++) {
            
            char target;
            if (i%2 == 0) {
                target = j % 2 == 0 ? 'W' : 'B';
            } else {
                target = j % 2 == 0 ? 'B' : 'W';
            }
            if (target != board[i][j]) cnt++;
        }
        
    }
    
    return cnt < 64 - cnt ? cnt : 64 - cnt;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int h,w;
    std::cin >> h >> w;
    for (int i=0; i<h; i++) {
        std::cin >> board[i];
    }
    int min = 1251;
    for (int i=0; i<=h - 8; i++) {
        for (int j=0; j<=w-8; j++) {
            // std::cout << "(" << i << "," << j << ")" << "\n";
            int value = solve(i, j);
            if (value < min) min = value;
        }
    }
    std::cout << min << "\n";
    return 0;
}
