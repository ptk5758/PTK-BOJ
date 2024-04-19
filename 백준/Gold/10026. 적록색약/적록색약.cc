#include <iostream>
#include <queue>
#include <cstring>

char arr[101][101];
bool visited[101][101];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
void dfs(int size, int x, int y) {
    visited[y][x] = true;
    for (int i=0; i<4; i++) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (nx < 0 || nx >= size) continue;
        if (ny < 0 || ny >= size) continue;
        if (arr[ny][nx] == arr[y][x] && !visited[ny][nx]) {
            dfs(size, nx, ny);
        }
    }
}
int main() {
    int size;
    std::cin >> size;
    for (int i=0; i<size; i++) {
        std::cin >> arr[i];
    }
    int cnt = 0;
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            if (!visited[i][j]) {
                dfs(size, j, i);
                cnt++;
            }
        }
    }
    for (int i=0; i<size; i++) {
        std::memset(visited, false, sizeof(visited));
    }
    
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            if (arr[i][j] == 'R' || arr[i][j] == 'G') arr[i][j] = 'A';
        }
    }
    int cnt2 = 0;
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            if (!visited[i][j]) {
                dfs(size, j, i);
                cnt2++;
            }
        }
    }
    std::cout << cnt << " " << cnt2;
    return 0;
}
