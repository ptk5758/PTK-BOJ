#include <iostream>
int dfs(bool **arr, bool *visited, int size, int now, int target, int count) {
    if (now == target) {
        return count;
    } else {
        for (int i=0; i<size; i++) {
            if (!visited[i] && arr[now][i]) {
                visited[i] = true;
                int value = dfs(arr, visited, size, i, target, count + 1);
                if (value != -1) return value;
            }
        }
        return -1;
    }
}
int main() {
    int n, ta, tb, m;
    std::cin >> n >> ta >> tb >> m;
    bool **arr = new bool* [n];
    for (int i=0; i<n; i++) arr[i] = new bool [n];
    int i = m;
    while (i--) {
        int a, b;
        std::cin >> a >> b;
        arr[a-1][b-1] = true;
        arr[b-1][a-1] = true;
    }
    bool *visited = new bool [n] {false};
    std::cout << dfs(arr, visited, n, ta-1, tb-1, 0) << "\n";
    
    return 0;
}
