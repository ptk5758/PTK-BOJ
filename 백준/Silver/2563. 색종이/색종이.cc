#include <iostream>
int arr[100][100] = { 0, };
void attach(int x, int y) {
    x--; y--;
    for (int i=y; i<y+10; i++) {
        if (i >= 100) continue;
        for (int j=x; j<x+10; j++) {
            if (j >= 100) continue;
            arr[i][j] = 1;
        }
    }
}
int main() {
    int n;
    std::cin >> n;
    while (n--) {
        int x ,y;
        std::cin >> x >> y;
        attach(x, y);
    }
    int cnt = 0;
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            if (arr[i][j]) cnt++;
            
        }
    }
    std::cout << cnt << "\n";
    return 0;
}
