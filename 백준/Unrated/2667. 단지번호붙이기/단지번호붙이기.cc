#include <iostream>
#include <vector>
#include <algorithm>
/*
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000
*/
struct Node {
	bool isBuild;
	bool isVisited = false;
};
Node* board[25][25];
// 왼 오 위 아
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int cnt;
void dfs(int y, int x, int size) {	
	// std::cout << "Start Y : " << y << " Start X : " << x << "\n";
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= size || ny >= size || nx < 0 || ny < 0) continue; // 맵을 벗어나는 경우
		Node* node = board[ny][nx];
		if (!node->isVisited && node->isBuild) {
			cnt++;
			node->isVisited = true;
			dfs(ny, nx, size);
		}
	}
}
int main() {
	std::vector<int> groupCount;
	int size;
	std::cin >> size;
	char* line = new char[size];
	for (int i = 0; i < size; i++) {
		std::cin >> line;
		for (int j = 0; j < size; j++) {
			Node* node = new Node();
			node->isBuild = line[j] == '1' ? true : false;
			board[i][j] = node;
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			// std::cout << "Start I : " << i << " Start J : " << j << "\n";
			Node* node = board[i][j];			
			if (!node->isBuild) continue; // 건물을 지을수 없는곳
			if (node->isVisited) continue;
			node->isVisited = true;
			cnt = 1;
			dfs(i, j, size);
			// std::cout << "Group Count : " << cnt << "\n";
			groupCount.push_back(cnt);
		}
	}
	std::sort(groupCount.begin(), groupCount.end());
	std::cout << groupCount.size() << "\n";
	for (int i = 0; i < groupCount.size(); i++) {
		std::cout << groupCount[i] << "\n";
	}
}

