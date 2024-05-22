#include <iostream>
#include <deque>

int main() {
    int n,m;
    int cnt = 0;
    std::deque<int> deque;
    std::cin >> n >> m;
    for (int i=0; i<n; i++) {
        deque.push_back(i+1);
    }
    
    for (int i = 0; i < m; ++i) {
        int value;
        std::cin >> value;

        int index = 0;
        for (int j = 0; j < deque.size(); ++j) {
            if (deque[j] == value) {
                index = j;
                break;
            }
        }

        if (index < deque.size() - index) {
            while (deque.front() != value) {
                deque.push_back(deque.front());
                deque.pop_front();
                ++cnt;
            }
        } else {
            while (deque.front() != value) {
                deque.push_front(deque.back());
                deque.pop_back();
                ++cnt;
            }
        }

        deque.pop_front();
    }
    std::cout << cnt;
    
    return 0;
}
