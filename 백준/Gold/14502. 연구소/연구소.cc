#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <cstring>
std::queue<std::tuple<int, int>> que;
int dx[] = {0, 0, -1, 1};
int dy[] = {1,-1,0 ,0};
int bfs(int **arr, int height, int width) {
    int count = 0;
    std::queue<std::tuple<int, int>> q(que);
    int **copy = new int* [height];
    for (int i=0; i<height; i++) {
        copy[i] = new int [width];
        for (int j=0; j<width; j++) {
            copy[i][j] = arr[i][j];
        }
        
    }
    while (q.size() > 0) {
        std::tuple<int, int> target = q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            int ny = std::get<0>(target) + dy[i];
            int nx = std::get<1>(target) + dx[i];
            if (ny < 0 || ny >= height) continue;
            if (nx < 0 || nx >= width) continue;
            if (copy[ny][nx] == 0) {
                copy[ny][nx] = 2;
                q.push(std::make_tuple(ny, nx));
            }
        }
    }
    
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            if (copy[i][j] == 0) count++;
        }
    }
    return count;
}
int max = 0;
void fn(int** arr, int height, int width, int count) {
    if (count == 3) {
        int count = bfs(arr, height, width);
        if (count > max) max = count;
//        std::cout << "Count -> " << count << "\n";
    } else {
        for (int i=0; i<height; i++) {
            for (int j=0; j<width; j++) {
                if (arr[i][j] == 0) {
                    arr[i][j] = 1;
                    fn(arr, height, width, count + 1);
                    arr[i][j] = 0;
                }
            }
        }
    }
}
int main() {
    int height, width;
    std::cin >> height >> width;
    
    int **arr = new int* [height];
    for (int i=0; i<height; i++) {
        arr[i] = new int [width];
        for (int j=0; j<width; j++) {
            std::cin >> arr[i][j];
            if (arr[i][j] == 2) que.push(std::make_tuple(i, j));
        }
    }
    fn(arr, height, width, 0);
    std::cout << max;

    for (int i=0; i<height; i++) {
        delete [] arr[i];
    }
    delete [] arr;
    
}
