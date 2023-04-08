#include <iostream>
#include <queue>
struct Node
{
	bool isBetue = false;
	bool isVisited = false;
	int x;
	int y;
	Node(int y, int x) {
		this->y = y;
		this->x = x;
	}
};
// 위 오 아 왼
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int result;
void bfs(Node*** board, Node* target, int height, int width) {
	if (target->isVisited) return; // 이미 방문한것
	if (!target->isBetue) return; // 배추가 없으면
	result++;
	std::queue<Node*> que;
	target->isVisited = true;
	que.push(target);
	while (!que.empty()) {
		Node* node = que.front();
		que.pop();
		// std::cout << "Y : " << node->y << " X :" << node->x << " 방문 \n";

		for (int i = 0; i < 4; i++) {
			int nx = node->x + dx[i];
			int ny = node->y + dy[i];
			if (nx < 0 || ny < 0 || nx >= width || ny >= height) continue;
			Node* child = board[ny][nx];
			if (child->isVisited) continue;
			if (!child->isBetue) continue;			
			child->isVisited = true;
			que.push(child);
		}
	}


}
int main() {
	Node*** board;
	int testCase;
	std::cin >> testCase;
	while (testCase--) {
		result = 0;
		int width, height, count, index=0;
		std::cin >> width >> height >> count;
		board = new Node** [height];
		for (int i = 0; i < height; i++) {
			board[i] = new Node*[width];			
			for (int j = 0; j < width; j++) {
				Node* node = new Node(i, j);
				board[i][j] = node;
			}
		}
		for (int i = 0; i < count; i++) {
			int x, y;
			std::cin >> x >> y;
			Node* node = board[y][x];
			node->isBetue = true;
		}
		// bfs 탐색 ㄱㄱ


		//
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				Node* node = board[i][j];
				bfs(board, node, height, width);
			}
		}
		std::cout << result << "\n";
	}

}