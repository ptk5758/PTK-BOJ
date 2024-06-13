#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
char arr[101][101];
int clusters[101][101];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};
std::queue<std::vector<std::pair<int, int>>> clusterQueue;
void testPrint(int h, int w) {
    for (int i=0; i<h; i++) {
        std::cout << arr[i] << "\n";
    }
}
// 초기화
void init(int h, int w) {
    for (int i=0; i<h; i++) {
        std::cin >> arr[i];
    }
}
// 나무가지 던지기 flag = true 왼쪽에서 던짐
void throwing(int y, bool flag, int width, std::pair<int, int> &broken) {
    int start = flag ? 0 : width - 1;
    if (flag) {
        while (start < width) {
            if (arr[y][start] == 'x') {
                arr[y][start] = '.';
                broken.first = y;
                broken.second = start;
                return;
            }
            start++;
        }
    } else {
        while (start >= 0) {
            if (arr[y][start] == 'x') {
                arr[y][start] = '.';
                broken.first = y;
                broken.second = start;
                return;
            }
            start--;
        }
    }
}
void groupClusterBFS(int h, int w, int id, std::pair<int, int> start) {
    std::queue<std::pair<int, int>> queue;
    std::vector<std::pair<int, int>> minerals;
    clusters[start.first][start.second] = id;
    queue.push(start);
    minerals.push_back(start);
    while (!queue.empty()) {
        std::pair<int, int> target = queue.front();
        queue.pop();
        for (int i=0; i<4; i++) {
            int ny = dy[i] + target.first;
            int nx = dx[i] + target.second;
            if (ny >= h || ny < 0) continue;
            if (nx >= w || nx < 0) continue;
            if (arr[ny][nx] == 'x' && clusters[ny][nx] == 0) {
                clusters[ny][nx] = id;
                queue.push(std::make_pair(ny, nx));
                minerals.push_back(std::make_pair(ny, nx));
            }
        }
    }
    clusterQueue.push(minerals);
}
bool isFalling(int h, std::vector<std::pair<int, int>> &minerals) {
    for (int i=0; i<minerals.size(); i++) {
        std::pair<int, int> mineral = minerals[i];
        if (mineral.first + 1 >= h) return false;
        if (clusters[mineral.first + 1][mineral.second] != 0 && clusters[mineral.first][mineral.second] != clusters[mineral.first + 1][mineral.second]) {
            return false;
        }
    }
//    std::cout << 5;
    return true;
}
void falling(std::vector<std::pair<int, int>> &cluster) {
    for (std::pair<int, int> &mineral : cluster) {
        arr[mineral.first][mineral.second] = '.';
    }
    for (std::pair<int, int> &mineral : cluster) {
        mineral.first++;
    }
    for (std::pair<int, int> &mineral : cluster) {
        arr[mineral.first][mineral.second] = 'x';
        clusters[mineral.first][mineral.second] = clusters[mineral.first - 1][mineral.second];
    }
    
}
void solve() {
    int h, w;
    std::pair<int, int> brokenPoint(-1, -1);
    std::cin >> h >> w;
    init(h, w);
    int n;
    std::cin >> n;
    for (int i=0; i<n; i++) {
        int target;
        std::cin >> target;
        throwing(h-target, i % 2 == 0, w, brokenPoint);
        if (brokenPoint.first != -1) {
            // std::vector<std::vector<bool>> visited(h, std::vector<bool>(w, false));
            memset(clusters, 0, sizeof(clusters));
            int groupCount = 0;
            for (int i=0; i<4; i++) {
                int ny = dy[i] + brokenPoint.first;
                int nx = dx[i] + brokenPoint.second;
                if (ny >= h || ny < 0) continue;
                if (nx >= w || nx < 0) continue;
                if (clusters[ny][nx] != 0) continue;
                if (arr[ny][nx] == 'x') {
                    groupClusterBFS(h, w, ++groupCount, std::make_pair(ny, nx));
                }
            }
            
            while (!clusterQueue.empty()) {
                std::vector<std::pair<int, int>> cluster = clusterQueue.front();
                clusterQueue.pop();
                while (isFalling(h, cluster)) {
                    falling(cluster);
                }
            }
        }
    }
    testPrint(h, w);
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}


