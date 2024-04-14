#include <iostream>
void dfs(int **arr, int height, int width, int y, int x, bool **visited) {
    if (y < 0 || y >= height) return;
    if (x < 0 || x >= width) return;
    if (visited[y][x]) return;
    visited[y][x] = true;
    if (arr[y][x] == 0) return;
    dfs(arr, height, width, y+1, x, visited);
    dfs(arr, height, width, y-1, x, visited);
    dfs(arr, height, width, y, x-1, visited);
    dfs(arr, height, width, y, x+1, visited);
    dfs(arr, height, width, y+1, x-1, visited);
    dfs(arr, height, width, y+1, x+1, visited);
    dfs(arr, height, width, y-1, x-1, visited);
    dfs(arr, height, width, y-1, x+1, visited);
}
int main() {
    while (true) {
        int w, h;
        std::cin >> w >> h;
        if (w == 0 && h == 0) break;
        int **arr = new int*[h];
        bool **visited = new bool*[h];
        for (int i=0; i<h; i++) {
            arr[i] = new int[w];
            visited[i] = new bool[w] {false,};
            for (int j=0; j<w; j++) {
                std::cin >> arr[i][j];
            }
        }
        
        
        int cnt = 0;
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                if (!visited[i][j] && arr[i][j]) {
                    dfs(arr, h, w, i, j, visited);
                    cnt++;
                }
            }
        }
        
        for (int i=0; i<h; i++) {
            delete [] arr[i];
            delete [] visited[i];
        }
        delete [] arr;
        delete [] visited;
        
        std::cout << cnt << "\n";
    }
    return 0;
}
