#include <iostream>
struct myqueue
{
    int arr[1000001];
    int front = 0;
    int rear = 0;
    bool emptt() {
        return front == rear;
    }
    void push(int value) {
        arr[rear++] = value;
    }
    int size() {
        return rear - front;
    }
    int pop() {
        return arr[front++];
    }
    int maxValue() {
        int max = -1;
        for (int i=front; i<rear; i++) {
            if (max < arr[i]) max = arr[i];
        }
        return max;
    }
};

void fn() {
    int n, index;
    std::cin >> n >> index;
    int value;
    myqueue que;
    for (int i=0; i<n; i++) {
        std::cin >> value;
        que.push(value);
    }
    index++;
    int cnt = 0;
    while (!que.emptt()) {
        int target = que.pop();
        index--;
        if (target < que.maxValue()) {
            que.push(target);
            if (index == 0) index += que.size();
        } else {
            cnt++;
            if (index == 0) break;
        }
    }
    std::cout << cnt << "\n";
}
int main() {
    int t;
    std::cin >> t;
    int i = t;
    while (i--) {
        fn();
    }
    return 0;
}
