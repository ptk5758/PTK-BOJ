#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

template <typename T>
using List = std::vector<T>;
template <typename T>
using Board = List<List<T>>;
template <typename T>
using Queue = std::queue<T>;

template <typename T1, typename T2>
using Pair = std::pair<T1, T2>;
using Location = Pair<int, int>;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int Solve()
{
	int n; std::cin >> n;
	Board<int> arr(n, List<int>(n, 0));
	Board<int> board(n, List<int>(n, 0));
	Board<bool> visited(n, List<bool>(n, false));
	Queue<Location> land;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			std::cin >> arr[i][j];
			if (arr[i][j] != 0)
			{
				land.push({i, j});
			}
		}
	}

	Queue<Location> t(land);

	int start = 1;
	while (!t.empty())
	{
		Queue<Location> queue;
		Location item = t.front(); t.pop();
		if (visited[item.first][item.second]) continue;
		visited[item.first][item.second] = true;
		board[item.first][item.second] = start;
		queue.push(item);
		while (!queue.empty())
		{
			Location now = queue.front(); queue.pop();
			for (int i=0; i<4; i++)
			{
				int ny = dy[i] + now.first;
				int nx = dx[i] + now.second;
				if (ny >= n || ny < 0 || nx >= n || nx < 0) continue;
				if (!visited[ny][nx] && arr[ny][nx] == 1) {
					visited[ny][nx] = true;
					board[ny][nx] = start;
					queue.push({ny, nx});
				}
			}
		}
		start++;
	}

	int min = 2100000000;
	bool flag = false;
	while (!land.empty())
	{
		Queue<Location> next;
		while (!land.empty())
		{
			Location now = land.front(); land.pop();
			visited[now.first][now.second] = true;
			for (int i=0; i<4; i++)
			{
				int ny = dy[i] + now.first;
				int nx = dx[i] + now.second;
				if (ny >= n || ny < 0 || nx >= n || nx < 0) continue;
				if (board[ny][nx] != 0 && board[now.first][now.second] != board[ny][nx]) {
					flag = true;
					min = std::min(min, arr[ny][nx] - 1 + arr[now.first][now.second] - 1);
				} else if (!visited[ny][nx] && arr[ny][nx] == 0) {
					arr[ny][nx] = arr[now.first][now.second] + 1;
					board[ny][nx] = board[now.first][now.second];
					next.push({ny, nx});
				}
			}
		}
		if (flag) return min;
		land = next;
	}

	
	return 0;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cout.tie(NULL);
	// Solve();
	std::cout << Solve() << "\n";
	return 0;
}