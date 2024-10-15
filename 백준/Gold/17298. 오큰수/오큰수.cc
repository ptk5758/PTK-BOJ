#include <iostream>
#include <stack>
typedef std::stack<int> Stack;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int arr[1000001];
    int NGE[1000001];
    Stack s;
    int n; std::cin >> n;
    for (int i=0; i<n; i++) std::cin >> arr[i];
    for (int i=0; i<n; i++) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            NGE[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) {
        NGE[s.top()] = -1;
        s.pop();
    }
    for (int i=0; i<n; i++) {
        std::cout << NGE[i] << " ";
    }
    std::cout << "\n";
    return 0;
}
