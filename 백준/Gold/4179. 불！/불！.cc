#include <iostream>
#include <queue>
#include <vector>

typedef std::queue<std::pair<int, int>> Queue;

Queue fireQueue, humanQueue;
Queue nextFire, nextHuman;

int Solution(char **board, int h, int w);


int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool HumanBFS(char **board, std::vector<std::vector<bool>> visited, int h, int w) {
    while (!humanQueue.empty()) {
        std::pair<int, int> position = humanQueue.front();
        humanQueue.pop();
        visited[position.first][position.second] = true;
        for (int i=0; i<4; i++) {
            int ny = dy[i] + position.first;
            int nx = dx[i] + position.second;
            if (ny < 0 || ny >= h) return true;
            if (nx < 0 || nx >= w) return true;
            if (!visited[ny][nx] && board[ny][nx] == '.') {
                visited[ny][nx] = true;
                board[ny][nx] = 'J';
                nextHuman.push({ny, nx});
            }
        }
    }
    while (!nextHuman.empty()) {
        humanQueue.push(nextHuman.front());
        nextHuman.pop();
    }
    return false;
}

void FireBFS(char **board, std::vector<std::vector<bool>> visited, int h, int w) {
    while (!fireQueue.empty()) {
        std::pair<int, int> position = fireQueue.front();
        fireQueue.pop();
        visited[position.first][position.second] = true;
        for (int i=0; i<4; i++) {
            int ny = dy[i] + position.first;
            int nx = dx[i] + position.second;
            if (ny < 0 || ny >= h) continue;
            if (nx < 0 || nx >= w) continue;
            if (!visited[ny][nx] && (board[ny][nx] == '.' || board[ny][nx] == 'J')) {
                visited[ny][nx] = true;
                board[ny][nx] = 'F';
                nextFire.push({ny, nx});
            }
        }
    }
    while (!nextFire.empty()) {
        fireQueue.push(nextFire.front());
        nextFire.pop();
    }
}

int Solution(char **board, int h, int w) {
    std::vector<std::vector<bool>> visited(h, std::vector<bool>(w, false));
    int result = 0;
    
    while (true) {
        result++;
        FireBFS(board, visited, h, w);
        if (HumanBFS(board, visited, h, w)) return result;
        if (humanQueue.size() == 0) return -1;
    }
}

int main() {
    
    // Config
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    //
    
    int h, w; std::cin >> h >> w;
    char **board = new char *[h];
    for (int i=0; i<h; i++) {
        board[i] = new char [w+1];
        std::cin >> board[i];
        for (int j=0; j<w; j++) {
            if (board[i][j] == 'J') {
                humanQueue.push({i, j});
            } else if (board[i][j] == 'F') {
                fireQueue.push({i, j});
            }
        }
    }
    
    int value = Solution(board, h, w);
    if (value == -1) {
        std::cout << "IMPOSSIBLE" << "\n";
    } else {
        std::cout << value << "\n";
    }
    
    for (int i=0; i<h; i++) {
        delete [] board[i];
    }
    delete[] board;
    
    return 0;
}
