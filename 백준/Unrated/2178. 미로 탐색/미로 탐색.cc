#include <iostream>
#include <queue>

struct Node
{
	bool isPass;
	bool isVisited = false;
	int depth = 1;
	int x, y;
	Node(int y, int x) {
		this->x = x;
		this->y = y;
	}
	
};
int dx[] = {0, 1, 0, -1};
int dy[] = { -1, 0, 1, 0 };
void bfs(Node*** board, Node* target, int height, int width) {
	std::queue<Node*> que;
	target->isVisited = true;
	que.push(target);
	while (!que.empty()) {
		Node* node = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = node->x + dx[i];
			int ny = node->y + dy[i];
			if (nx < 0 || ny < 0 || nx >= width || ny >= height) continue;
			Node* child = board[ny][nx];
			if (child->isVisited) continue;
			if (!child->isPass) continue;
			child->isVisited = true;
			child->depth = node->depth + 1;
			que.push(child);
		}
	}
}
int main() {
	int height, width;
	std::cin >> height >> width;
	Node*** board = new Node** [height];
	char* line = new char[width];
	for (int i = 0; i < height; i++) {
		board[i] = new Node* [width];
		std::cin >> line;
		for (int j = 0; j < width; j++) {
			Node* node = new Node(i, j);
			node->isPass = line[j] == '1' ? true : false;
			board[i][j] = node;
		}
	}
	Node* target = board[0][0];
	bfs(board, target, height, width);
	std::cout << board[height - 1][width - 1]->depth;
}