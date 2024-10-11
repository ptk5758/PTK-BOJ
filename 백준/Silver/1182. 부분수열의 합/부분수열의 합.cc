#include <iostream>
#include <vector>

typedef std::vector<int> List;
int sum(List list) {
    int result = 0;
    for (int value : list) {
        result += value;
    }
    return result;
}
void Solve(int index, int s, int &result, List &nums, List list) {
    if (list.size() > 0) {
        if (s == sum(list)) {
            result++;
        }
    }
    for (int i=index; i<nums.size(); i++) {
        list.push_back(nums[i]);
        Solve(i+1, s, result, nums, list);
        list.pop_back();
    }
}
int main() {
    int n, s; std::cin >> n >> s;
    List nums;
    for (int i=0; i<n; i++) {
        int value; std::cin >> value;
        nums.push_back(value);
    }
    int result = 0;
    Solve(0, s, result, nums, List());
    std::cout << result << "\n";
    return 0;
}
