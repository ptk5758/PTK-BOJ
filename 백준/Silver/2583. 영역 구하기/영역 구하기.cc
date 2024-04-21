#include <iostream>
#include <vector>
#include <algorithm>

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
void dfs(bool **arr, int h, int w, int x, int y, bool **visited, int *count) {
    visited[y][x] = true;
    *count = *count + 1;
    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (ny < 0 || ny >= h) continue;
        if (nx < 0 || nx >= w) continue;
        if (!arr[ny][nx] && !visited[ny][nx]) {
            dfs(arr, h, w, nx, ny, visited, count);
        }
    }
}
int main() {
    int h, w, k;
    std::cin >> h >> w >> k;
    bool **arr = new bool*[h];
    bool **visited = new bool*[h];
    // 메모리 할당
    for (int i=0; i<h; i++) {
        arr[i] = new bool[w];
        visited[i] = new bool[w];
    }
    
    // 데이터 삽입
    int i = k;
    while (i--) {
        int x, y, a, b;
        std::cin >> x >> y >> a >> b;
        for (int j=y; j<b; j++) {
            for (int t=x; t<a; t++) {
                arr[j][t] = true;
            }
        }
    }

    // 깊이 우선 탐색
    std::vector<int> vec;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (!arr[i][j] && !visited[i][j]) {
                int count = 0;
                dfs(arr, h, w, j, i, visited, &count);
                vec.push_back(count);
            }
        }
    }
    
    // 정렬
    std::sort(vec.begin(), vec.end());
    std::cout << vec.size() << "\n";
    // 출력
    for (int value : vec) {
        std::cout << value << " ";
    }
    

    
    // 메모리 헤제 부분
    for (int i=0; i<h; i++) {
        delete [] visited[i];
        delete [] arr[i];
    }
    delete [] visited;
    delete [] arr;
    return 0;
}
