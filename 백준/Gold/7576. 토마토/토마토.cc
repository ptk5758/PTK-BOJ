#include <iostream>
#include <queue>
#include <vector>
int main() {
    
    int m, n;
    std::cin >> m >> n;
    int arr[1001][1001];
    std::queue<std::vector<int>> que;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int value;
            std::cin >> value;
            arr[i][j] = value;
            if (arr[i][j] == 1) {
                std::vector<int> vec;
                vec.push_back(j);
                vec.push_back(i);
                que.push(vec);
            }
        }
    }
    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};
    while (que.size() > 0) {
        
        std::vector<int> target = que.front();
        que.pop();
        for (int i=0; i<4; i++) {
            int nx = target[0] + dx[i];
            int ny = target[1] + dy[i];
            if (nx < 0 || nx >= m) continue;
            if (ny < 0 || ny >= n) continue;
            if (arr[ny][nx] == 0) {
                arr[ny][nx] = arr[target[1]][target[0]]+1;
                std::vector<int> v;
                v.push_back(nx);
                v.push_back(ny);
                que.push(v);
            }
        }
    }
    int max = -1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (max < arr[i][j] - 1) max = arr[i][j] - 1;
            else if (arr[i][j] == 0) {
                std::cout << -1;
                return 0;
            }
        }
        
    }
    std::cout << max;
    return 0;
    
}
