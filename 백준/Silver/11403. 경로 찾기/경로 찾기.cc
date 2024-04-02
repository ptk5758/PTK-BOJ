#include <iostream>
#include <vector>
#include <queue>

bool bfs(int** arr, int size, int now, int target, std::vector<bool> visited) {
    std::queue<int> que;
    for (int i=0; i<size; i++) {
        if (arr[now][i] == 1) que.push(i);
    }
    while (que.size() > 0) {
        int num = que.front();
        que.pop();
        if (num == target) return true;
        for (int i=0; i<size; i++) {
            if (arr[num][i] == 1) {
                if (!visited[i]) {
                    que.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    return false;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin >> n;
    int **arr = new int*[n];
    for (int i=0; i<n; i++) {
        arr[i] = new int[n];
        for (int j=0; j<n; j++) {
            std::cin >> arr[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            std::vector<bool> visited(n, false);
            std::cout << bfs(arr, n, i, j, visited) << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
