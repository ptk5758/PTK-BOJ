#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

template <typename T1, typename T2>
using Pair = std::pair<T1, T2>;
using Location = Pair<int, int>;
using Cam = Pair<int, Location>;

template <typename T>
using List = std::vector<T>;
using Board = List<List<int>>;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int min = 2100000000;

void Visit(int y, int x, int &n, int &m, int d, Board &arr)
{    
    d = d % 4;
    if (y >= n || y < 0 || x >= m || x < 0) return;
    if (arr[y][x] == 6) return;
    arr[y][x] = 7;
    int ny = dy[d] + y;
    int nx = dx[d] + x;
    Visit(ny, nx, n, m, d, arr);
}
void DFS(int index, List<Cam> &cams, Board arr, Board &original, int &n, int &m)
{
    if (index == cams.size())
    {
        // std::cout << "---------------------------\n";
        int count = 0;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (!arr[i][j]) count++;
                // std::cout << arr[i][j] << " ";                
            }
            // std::cout << "\n";
        }
        // std::cout << "Count : " << count << "\n";
        // std::cout << "---------------------------\n";
        min = std::min(min, count);
        return;
    }
    for (int i=0; i<4; i++)
    {
        Cam cam = cams[index];
        Location now = cam.second;        
        Board c(arr);
        switch (cam.first)
        {
            case 1:
                Visit(now.first, now.second, n, m, i, c);
                break;
            case 2:
                Visit(now.first, now.second, n, m, i, c);
                Visit(now.first, now.second, n, m, i + 2, c);
                break;
            case 3:
                Visit(now.first, now.second, n, m, i, c);
                Visit(now.first, now.second, n, m, i + 1, c);
                break;
            case 4:
                Visit(now.first, now.second, n, m, i, c);
                Visit(now.first, now.second, n, m, i + 1, c);
                Visit(now.first, now.second, n, m, i + 3, c);
                break;
            case 5:
                Visit(now.first, now.second, n, m, i, c);
                Visit(now.first, now.second, n, m, i + 1, c);
                Visit(now.first, now.second, n, m, i + 2, c);
                Visit(now.first, now.second, n, m, i + 3, c);
                break;
            default :
                break;
        }
        DFS(index + 1, cams, c, original, n, m);
    }
    // arr = Board(original);

    
}
void Solve()
{
    int n, m; std::cin >> n >> m;
    Board arr(n, List<int>(m));
    List<Cam> cams;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            std::cin >> arr[i][j];
            if (arr[i][j] > 0 && arr[i][j] < 6) cams.push_back({arr[i][j], {i, j}});
        }
    }
    Board t(arr);
    DFS(0, cams, t, arr, n, m);
    std::cout << min << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);    
    Solve();
    return 0;
}