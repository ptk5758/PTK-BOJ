#include <iostream>
#include "queue"
#include "vector"
#define FAILED "IMPOSSIBLE"
typedef std::queue<std::pair<int, int>> Queue;
typedef std::vector<std::vector<bool>> Visited;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
bool HumanBFS(char **board, Queue &human, Visited &visited, int h, int w) {
    Queue next;
    while (!human.empty()) {
        std::pair<int, int> location = human.front();
        human.pop();
        visited[location.first][location.second] = true;
        for (int i=0; i<4; i++) {
            int ny = dy[i] + location.first;
            int nx = dx[i] + location.second;
            if (ny < 0 || ny >= h) {
                return true;
            }
            if (nx < 0 || nx >= w) {
                return true;
            }
            if (!visited[ny][nx]) {
                if (board[ny][nx] == '.') {
                    board[ny][nx] = '@';
                    next.push({ny, nx});
                }
                visited[ny][nx] = true;
            }
        }
    }
    
    human = next;
    return false;
}
void FireBFS(char **board, Queue &fire, Visited &visited, int h, int w) {
    Queue next;
    while (!fire.empty()) {
        std::pair<int, int> location = fire.front();
        fire.pop();
        visited[location.first][location.second] = true;
        for (int i=0; i<4; i++) {
            int ny = dy[i] + location.first;
            int nx = dx[i] + location.second;
            if (ny < 0 || ny >= h) continue;
            if (nx < 0 || nx >= w) continue;
            if (!visited[ny][nx]) {
                if (board[ny][nx] == '.' || board[ny][nx] == '@') {
                    board[ny][nx] = '*';
                    next.push({ny, nx});
                }
                visited[ny][nx] = true;
            }
        }
    }
    fire = next;
}
int Solve() {
    int w,h; std::cin >> w >> h;
    char **board = new char *[h];
    Queue fire, human;
    Visited visited(h, std::vector<bool>(w, false));
    for (int i=0; i<h; i++) {
        board[i] = new char [w+1];
        std::cin >> board[i];
        for (int j=0; j<w; j++) {
            if (board[i][j] == '@') human.push({i, j});
            else if (board[i][j] == '*') fire.push({i, j});
        }
    }
    int result = 0;
    while (true) {
        result++;
        FireBFS(board, fire, visited, h, w);
        if (HumanBFS(board, human, visited, h, w)) {
            return result;
        }
        if (human.empty()) break;
    }
    return -1;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int t; std::cin >> t;
    while (t--) {
        int value = Solve();
        if (value == -1) {
            std::cout << FAILED << "\n";
        } else {
            std::cout << value << "\n";
        }
    }
    
    return 0;
}
