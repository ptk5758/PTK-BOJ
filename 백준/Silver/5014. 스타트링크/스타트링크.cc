#include <iostream>
#include "queue"
#define FAILED "use the stairs"
int Solve();
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int value = Solve();
    if (value == -1) {
        std::cout << FAILED << "\n";
    } else {
        std::cout << value << "\n";
    }
    
    return 0;
}

int Solve() {
    int f,s,g,u,d; std::cin >> f >> s >> g >> u >> d;
    std::queue<int> floorQueue, nextQueue;
    bool visited[1000001] = {false,};
    floorQueue.push(s);
    visited[s] = true;
    
    int result = 0;
    while (!floorQueue.empty()) {
        
        while (!floorQueue.empty()) {
            int floor = floorQueue.front();
            floorQueue.pop();
            if (floor == g) { return result; }
            int nu = floor + u;
            int nd = floor - d;
            
            if (nu <= f && !visited[nu]) {
                visited[nu] = true;
                nextQueue.push(nu);
            }
            
            if (nd > 0 && !visited[nd]) {
                visited[nd] = true;
                nextQueue.push(nd);
            }
        }
        result++;
        while (!nextQueue.empty()) {
            floorQueue.push(nextQueue.front());
            nextQueue.pop();
        }
    }
    
    
    return -1;
}
