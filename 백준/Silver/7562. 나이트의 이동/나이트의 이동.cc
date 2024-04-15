#include <iostream>
#include <queue>
#include <tuple>
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int bfs(int **arr, int size, std::tuple<int, int> start, std::tuple<int, int> target) {
    std::queue<std::tuple<int,int>> que;
    que.push(start);
    while (que.size() > 0) {
        std::tuple<int, int> now = que.front();
        que.pop();
        int nowx = std::get<1>(now);
        int nowy = std::get<0>(now);
        if (nowx == std::get<1>(target) && nowy == std::get<0>(target)) {
            return arr[nowy][nowx];
        }
        for (int i=0; i<8; i++) {
            int nx = std::get<1>(now) + dx[i];
            int ny = std::get<0>(now) + dy[i];
            if (nx < 0 || nx >= size) continue;
            if (ny < 0 || ny >= size) continue;
            if (arr[ny][nx] != 0) continue;
            arr[ny][nx] = arr[nowy][nowx] + 1;
            que.push(std::make_tuple(ny, nx));
        }
    }
    return 0;
}
int main() {
    int t;
    std::cin >> t;
    for (int k=0; k<t; k++) {
        int size;
        std::cin >> size;
        int **arr = new int*[size];
        for (int i=0; i<size; i++) {
            arr[i] = new int[size]();
        }
        int nx, ny;
        int tx, ty;
        std::cin >> nx >> ny >> tx >> ty;
        int distance = bfs(arr, size, std::make_tuple(nx, ny), std::make_tuple(tx, ty));
        std::cout << distance << "\n";
        for (int i=0; i<size; i++) {
            delete [] arr[i];
        }
        delete [] arr;
    }
    
}
