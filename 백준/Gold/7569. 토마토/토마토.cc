#include <iostream>
#include <queue>
#include <tuple>

int main() {
    int row, column, height;
    std::cin >> row >> column >> height;
    std::queue<std::tuple<int,int,int>> que; // z y x
    int ***arr = new int **[height];
    for (int i=0; i<height; i++) {
        arr[i] = new int *[column];
        for (int j=0; j<column; j++) {
            arr[i][j] = new int [row];
            for (int k=0; k<row; k++) {
                int value;
                std::cin >> value;
                arr[i][j][k] = value;
                if (arr[i][j][k] == 1) {
                    que.push(std::make_tuple(i,j,k));
                }
            }
        }
    }
    int dx[] = {0, 0, 0, 0, -1, 1};
    int dy[] = {0, 0, 1, -1, 0, 0};
    int dz[] = {1, -1, 0, 0, 0, 0};
    while (que.size() > 0) {
        std::tuple<int, int, int> target = que.front();
        int value = arr[std::get<0>(target)][std::get<1>(target)][std::get<2>(target)];
        que.pop();
        for (int i=0; i<6; i++) {
            int nz = std::get<0>(target) + dz[i];
            int ny = std::get<1>(target) + dy[i];
            int nx = std::get<2>(target) + dx[i];
            if (nz < 0 || nz >= height) continue;
            if (ny < 0 || ny >= column) continue;
            if (nx < 0 || nx >= row) continue;
            if (arr[nz][ny][nx] == 0) {
                arr[nz][ny][nx] = value + 1;
                que.push(std::make_tuple(nz, ny, nx));
            }
        }
    }
    int max = 0;
    for (int i=0; i<height; i++) {
        
        for (int j=0; j<column; j++) {
        
            for (int k=0; k<row; k++) {
                if (arr[i][j][k] == 0) {
                    std::cout << -1;
                    return 0;
                }
                if (max < arr[i][j][k] + 1) {
                    max = arr[i][j][k];
                }
            }
            
        }
        
    }
    std::cout << max - 1;
    return 0;
}
