#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
template <typename T>
using List = std::vector<T>;
template <typename T>
using Board = List<List<T>>;
template <typename T1, typename T2>
using Pair = std::pair<T1, T2>;
using Location = std::pair<int, int>;
template <typename T>
using Queue = std::queue<T>;

int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };
void BFSIce(Board<int> &arr, Queue<Location> &ices, Board<bool> &visited, int &n, int &m)
{
	Queue<Pair<Location, int>> queue;

	Queue<Location> next;

	while (!ices.empty())
	{
		Location now = ices.front(); ices.pop();
		int y = now.first;
		int x = now.second;
		visited[y][x] = true;
		int count = 0;
		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
			if (arr[ny][nx] == 0) {
				count++;
			}
		}
		queue.push({ {y, x}, arr[y][x] - count});
	}

	while (!queue.empty())
	{
		Pair<Location, int> p = queue.front(); queue.pop();
		Location now = p.first;
		arr[now.first][now.second] = std::max(0, p.second);
		if (arr[now.first][now.second] != 0) next.push({ now.first, now.second });
	}
	while (!next.empty()) {
		ices.push(next.front());
		next.pop();
	}
}
int CountIce(Location&location, Board<int> &arr)
{
	Board<bool> visited(arr.size(), List<bool>(arr[0].size(), false));	
	Queue<Location> queue;
	queue.push({ location.first, location.second });
	visited[location.first][location.second] = true;
	int count = 0;
	while (!queue.empty())
	{
		count++;
		Location now = queue.front(); queue.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + now.first;
			int nx = dx[i] + now.second;

			if (ny >= arr.size() || ny < 0 || nx >= arr[0].size() || nx < 0) continue;
			if (!visited[ny][nx] && arr[ny][nx] > 0) {
				queue.push({ ny, nx });
				visited[ny][nx] = true;
			}
		}
	}
	return count;
}

int Solve()
{
	int n, m; std::cin >> n >> m;
	Board<int> arr(n, List<int>(m));
	Queue<Location> ices;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cin >> arr[i][j];
			if (arr[i][j] > 0) ices.push({i, j});
		}
	}
	int count = 0;
	Board<bool> visited(n, List<bool>(m, false));
	while (!ices.empty())
	{
		if (CountIce(ices.front(), arr) != ices.size()) return count;
		count++;
		for (int i = 0; i < n; i++) std::fill(visited[i].begin(), visited[i].end(), false);
		BFSIce(arr, ices, visited, n, m);
	}
	return 0;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::cout << Solve() << "\n";
	return 0;
}