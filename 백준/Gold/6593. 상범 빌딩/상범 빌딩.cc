#include <iostream>
#include "tuple"
#include "queue"
#include "vector"
#define FAILED "Trapped!"
typedef std::tuple<int, int, int> vector; // z, y, x
typedef std::queue<vector> Queue;
typedef std::vector<std::vector<std::vector<bool>>> Visited;
int dx[] = {0,0,-1,1,0,0};
int dy[] = {1,-1,0,0,0,0};
int dz[] = {0,0,0,0,1,-1};
bool EscapeBFS(char ***board, Queue &human, Visited &visited, vector size) {
    Queue next;
    while (!human.empty()) {
        vector position = human.front();
        human.pop();
        for (int i=0; i<6; i++) {
            int nz = dz[i] + std::get<0>(position);
            int ny = dy[i] + std::get<1>(position);
            int nx = dx[i] + std::get<2>(position);
            if (nz < 0 || nz >= std::get<0>(size)) continue;
            if (ny < 0 || ny >= std::get<1>(size)) continue;
            if (nx < 0 || nx >= std::get<2>(size)) continue;
            if (board[nz][ny][nx] == '.') {
                board[nz][ny][nx] = 'S';
                next.push({nz, ny, nx});
            } else if (board[nz][ny][nx] == 'E') {
                return true;
            }
        }
    }
    human = next;
    return false;
}
int Solve(int l, int r, int c) {
    char ***board = new char **[l];
    Visited visited(l,
                    std::vector<std::vector<bool>>(r,
                                                   std::vector<bool>(c, false)));
    Queue human;
    vector size(l,r,c);
    for (int i=0; i<l; i++) {
        board[i] = new char *[r];
        for (int j=0; j<r; j++) {
            board[i][j] = new char [c + 1];
            std::cin >> board[i][j];
            for (int k=0; k<c; k++) {
                if (board[i][j][k] == 'S') {
                    human.push({i, j, k});
                    visited[i][j][k] = true;
                }
            }
        }
    }
    int result = 0;
    while (true) {
        result++;
        if (EscapeBFS(board, human, visited, size)) {
            return result;
        }
        if (human.empty()) {
            break;
        }
    }
    return -1;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int L,R,C;
    while (true) {
        std::cin >> L >> R >> C;
        if (!L && !R && !C) {
            return 0;
        }
        int value = Solve(L, R, C);
        if (value != -1) {
            std::cout << "Escaped in " << value << " minute(s)." << "\n";
        } else {
            std::cout << FAILED << "\n";
        }
        
    }
    return 0;
}
