#include <iostream>
#include <queue>
#include <tuple>
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
void bfs(int **arr, bool **visited, int size, int y, int x, int height) {
    std::queue<std::tuple<int, int>> que;
    que.push(std::make_tuple(y, x));
    visited[y][x] = true;
    while (que.size() > 0) {
        std::tuple<int, int> now = que.front();
        que.pop();
        for (int i=0; i<4; i++) {
            int ny = dy[i] + std::get<0>(now);
            int nx = dx[i] + std::get<1>(now);
            if (ny < 0 || ny >= size) continue;
            if (nx < 0 || nx >= size) continue;
            if (!visited[ny][nx] && arr[ny][nx] > height) {
                que.push(std::make_tuple(ny, nx));
                visited[ny][nx] = true;
            }
        }
    }
}
int main() {
    int n;
    std::cin >> n;
    int **arr = new int*[n];
    bool **visited = new bool*[n];
    int height = 0;
    for (int i=0; i<n; i++) {
        arr[i] = new int[n];
        visited[i] = new bool[n] {false};
        for (int j=0; j<n; j++) {
            std::cin >> arr[i][j];
            if (height < arr[i][j]) height = arr[i][j];
        }
    }
    int max = -1;
    for (int k=0; k<height; k++) {
        int cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (!visited[i][j] && arr[i][j] > k) {
                    cnt++;
                    bfs(arr, visited, n, i, j, k);
                    if (cnt > max) max = cnt;
                }
            }
        }
//        std::cout << "Height : " << k << " Count -> " << cnt << "\n";
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                visited[i][j] = false;
            }
        }
        
    }
    std::cout << max;
    return 0;
}
