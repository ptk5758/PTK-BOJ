#include <iostream>
#include <queue>
#include <vector>

int bfs(int start, int target) {
    if (start == target) return 0;
    std::queue<int> que;
    std::vector<bool> visited(100001, false);  // 범위 +1 만큼의 방문 배열
    que.push(start);
    visited[start] = true;
    int depth = 0;

    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; i++) {
            int now = que.front();
            que.pop();

            // 다음 상태들에 대한 처리
            std::vector<int> next_states = {now + 1, now - 1, now * 2};
            for (int next : next_states) {
                if (next >= 0 && next <= 100000 && !visited[next]) {
                    if (next == target) return depth + 1;
                    que.push(next);
                    visited[next] = true;
                }
            }
        }
        depth++;
    }
    return -1; // 타겟에 도달할 수 없는 경우
}

int main() {
    int s, t;
    std::cin >> s >> t;
    int distance = bfs(s, t);
    std::cout << distance;
    
    return 0;
}
