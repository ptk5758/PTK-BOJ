#include <iostream>
#include <queue>
#include <vector>

int dx[] = { 0, 0, -1, 1};
int dy[] = { 1, -1, 0, 0 };
bool visited[1501][1501] = { false, };
bool swanBFS(char **arr, std::queue<std::pair<int, int>> &swans, int h, int w) {
	std::queue<std::pair<int, int>> que(swans);
	while (!que.empty()) {
		std::pair<int, int> target = que.front();
		que.pop();
		visited[target.first][target.second] = true;
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + target.first;
			int nx = dx[i] + target.second;
			if (ny >= h || ny < 0) continue;
			if (nx >= w || nx < 0) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = true;
			if (arr[ny][nx] == 'X') {
				arr[ny][nx] = '.';
				swans.push(std::make_pair(ny, nx));
			}
			else if (arr[ny][nx] == '.') que.push(std::make_pair(ny, nx));
			else return true;
		}
	}
	return false;
}

void waterBFS(char** arr, std::queue<std::pair<int, int>> &water, int h, int w) {
	std::queue<std::pair<int, int>> que(water), next;
	while (!que.empty()) {
		std::pair<int, int> target = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + target.first;
			int nx = dx[i] + target.second;
			if (ny >= h || ny < 0) continue;
			if (nx >= w || nx < 0) continue;
			if (arr[ny][nx] == 'X') {
				arr[ny][nx] = '.';
				next.push(std::make_pair(ny, nx));
			}
		}
	}	
	water = next;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	// 초기화
	int h, w;
	std::cin >> h >> w;
	char **arr = new char * [h];	
	std::queue<std::pair<int, int>> water, swans;
	std::pair<int, int> swan;
	for (int i = 0; i < h; i++) {
		arr[i] = new char[w + 1];
		std::cin >> arr[i];
		for (int j = 0; j < w; j++) {
			if (arr[i][j] != 'X') water.push(std::make_pair(i, j));
			if (arr[i][j] == 'L') swan = std::make_pair(i, j);
		}
	}
	swans.push(swan);
	int cnt = 0;
	while (true) {
		if (swanBFS(arr, swans, h, w)) break;
		cnt++;
		waterBFS(arr, water, h, w);
		/*std::cout << "-----------------------------------\n";
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				std::cout << arr[i][j] << " ";
			}
			std::cout << "\n";
		}*/
	}

	std::cout << cnt;

	// 할당 해제
	for (int i = 0; i < h; i++) {
		delete arr[i];
	}
	delete[] arr;
	return 0;
}