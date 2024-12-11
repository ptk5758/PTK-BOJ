#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using Location = std::tuple<int, int, int>;
using Queue = std::queue<Location>;

int arr[1001][1001][2] = { 0, };
int board[1001][1001][2] = { 0, };
bool visited[1001][1001][2] = { 0, };
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
void Solve()
{
	int n, m; std::cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		std::string str; std::cin >> str;
		for (int j = 0; j < m; j++)
		{
			arr[i][j][0] = str[j] - '0';
			arr[i][j][1] = str[j] - '0';
		}
	}
	if (n == 1 && m == 1)
	{
		std::cout << 1 << "\n";
		return;
	}
	Queue queue;
	queue.push({0,0,0});
	visited[0][0][0] = true;
	int depth = 1;
	while (!queue.empty())
	{
		Queue nextQueue;
		while (!queue.empty())
		{
			Location now = queue.front(); queue.pop();
			int y = std::get<0>(now);
			int x = std::get<1>(now);
			int z = std::get<2>(now);
			for (int i = 0; i < 4; i++)
			{
				int ny = dy[i] + y;
				int nx = dx[i] + x;
				if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
				if (visited[ny][nx][z]) continue;
				if (arr[ny][nx][z] == 0)
				{
					visited[ny][nx][z] = true;
					board[ny][nx][z] = depth + 1;
					nextQueue.push({ny, nx, z});
				}
				else if (arr[ny][nx][z] == 1)
				{
					if (z == 0)
					{
						visited[ny][nx][z + 1] = true;
						board[ny][nx][z + 1] = depth + 1;
						nextQueue.push({ ny, nx, z + 1 });
					}
				}
			}
		}
		depth++;
		queue = nextQueue;
	}
	
	int a = board[n - 1][m - 1][0];
	int b = board[n - 1][m - 1][1];
	int result;
	if (a > b)
	{
		result = b != 0 ? b : a;
	}
	else
	{
		result = a != 0 ? a : b;
	}

	std::cout << (result == 0 ? -1 : result) << "\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	Solve();
	return 0;
}