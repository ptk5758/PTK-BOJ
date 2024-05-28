#include <iostream>
struct queue {
    int *arr;
    int front;
    int rear;
    int length;
    queue (int size) {
        arr = new int[size];
        for (int i=0; i<size; i++) {
            arr[i] = i+1;
        }
        front = 0;
        rear = size;
        length = size;
    }
    ~queue () {
        delete [] arr;
    }
    void push (int value) {
        arr[rear++ % length] = value;
    }
    int pop () {
        return arr[front++ % length];
    }
    bool empty () {
        return front == rear;
    }
    

};
int main() {
    int n;
    std::cin >> n;
    queue que(n);
    while (!que.empty()) {
        std::cout << que.pop() << " ";
        que.push(que.pop());
        
    }
    return 0;
}
