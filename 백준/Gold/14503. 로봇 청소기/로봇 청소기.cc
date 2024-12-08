#include <iostream>
#include <queue>
#include <vector>

typedef std::vector<int> Cleaned;
typedef std::vector<Cleaned> Board;
typedef std::pair<int, int> Location;
typedef std::queue<Location> Queue;

// y , x
const Location direction[] = {
    {-1, 0}, // 북
    {0, 1}, // 동
    {1, 0}, // 남
    {0, -1} // 서
};
int t = 0;
void Print(int n, int d, int m, int x, int y, Board &board)
{
    std::cout << t++ << "=================================\nD:" << d << "\n";
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (y == i && x == j) {
                std::cout << '*' << " ";
            } else {
                std::cout << board[i][j] << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "=================================\n";

}
bool CheckCleanAble(Board &board, int &n, int &m, int &y, int &x)
{
    for (int i=0; i<4; i++)
    {
        Location nd = direction[i];
        int ny = nd.first + y;
        int nx = nd.second + x;
        if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
        if (!board[ny][nx]) return true;
    }
    return false;
}
int Solve()
{
    int n, m; std::cin >> n >> m;
    Board board(n, Cleaned(m, 0));    
    int r,c,d; std::cin >> r >> c >> d;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            bool value; std::cin >> value;
            board[i][j] = value;
        }
    }
    int result = 0;
    Queue queue;
    queue.push({r, c});
    while (!queue.empty())
    {
        Location location = queue.front(); queue.pop();
        int y = location.first;
        int x = location.second;
        // std::cout << "Y : " << y << " X : " << x << "\n";
        if (!board[y][x]) {
            // Print(n, d, m, x, y, board);
            board[y][x] = -1;
            result++;
        }
        bool flag = CheckCleanAble(board, n, m, y, x);
        if (flag) {
            while (true)
            {
                d = (d - 1 + 4) % 4;
                Location nd = direction[d]; // d = 2 {-1 , 0} 6, 3
                int ny = nd.first + y;
                int nx = nd.second + x;
                // std::cout << "D : " << d << " NY :" << ny << " NX : " << nx << "\n";
                if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
                if (!board[ny][nx]) {
                    queue.push({ny, nx});
                    break;
                }
            }
        } else {
            Location nd = direction[(d + 2) % 4];
            int ny = nd.first + y;
            int nx = nd.second + x;            
            // std::cout << "D : " << d << " NY :" << ny << " NX : " << nx << "\n";
            if (ny >= n || ny < 0 || nx >= m || nx < 0 || board[ny][nx] == 1) {
                break;
            } else {
                queue.push({ny, nx});
            }
        }
    }
    return result;
}
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int result = Solve();
    std::cout << result << "\n";
    return 0;
}