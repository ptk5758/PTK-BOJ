#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef std::vector<int> List;
typedef std::vector<bool> Visited;
typedef std::set<int> Set;
typedef std::pair<Set, Set> Pair;
void DFS(int start, List &nums, Visited visited, Set indexSet, Set valueSet, Set &answer) {
    indexSet.insert(start);
    valueSet.insert(nums[start]);
    visited[start] = true;
    if (indexSet == valueSet) {
        for (int value : indexSet) {
            answer.insert(value);
        }
        return;
    }
    if (!visited[nums[start]]) {
        DFS(nums[start], nums, visited, indexSet, valueSet, answer);
    }
}
void Solve(int n, List &nums) {
    Set answer;
    for (int i=1; i<=n; i++) {
        Visited visited(n + 1, false);
        DFS(i, nums, visited, Set(), Set(), answer);
    }
    std::cout << answer.size() << "\n";
    for (int value : answer) {
        std::cout << value << "\n";
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n; std::cin >> n;
    List nums;
    nums.push_back(0);
    for (int i=0; i<n; i++) {
        int value; std::cin >> value;
        nums.push_back(value);
    }
    Solve(n, nums);
    return 0;
}
