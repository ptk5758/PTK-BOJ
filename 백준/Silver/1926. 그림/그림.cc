#include <iostream>
#include <vector>
#include <queue>
typedef std::vector<std::vector<bool>> Board;
void Init(Board &board, int h, int w);
int GetPictureSize(Board &board, Board &visited, int h, int w, int y, int x);

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int h, w; std::cin >> h >> w;
	Board board(h, std::vector<bool>(w, false)), visited(h, std::vector<bool>(w, false));
	Init(board, h, w);
	int max = 0;
	int count = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (!visited[i][j] && board[i][j]) {
				count++;
				int size = GetPictureSize(board, visited, h, w, i, j);
				if (max < size) max = size;
			}
		}
	}
	std::cout << count << "\n" << max;
}

void Init(Board &board, int h, int w) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int value; std::cin >> value;
			board[i][j] = value;
		}
	}
}

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int GetPictureSize(Board& board, Board& visited, int h, int w, int y, int x) {
	std::queue<std::pair<int, int>> queue;
	queue.push({ y, x });
	visited[y][x] = true;
	int result = 1;
	while (!queue.empty()) {
		std::pair<int, int> now = queue.front();
		queue.pop();
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + now.first;
			int nx = dx[i] + now.second;
			if (ny < 0 || ny >= h) continue;
			if (nx < 0 || nx >= w) continue;
			if (!visited[ny][nx] && board[ny][nx]) {
				visited[ny][nx] = true;
				result++;
				queue.push({ ny, nx });
			}
		}
	}
	return result;
}