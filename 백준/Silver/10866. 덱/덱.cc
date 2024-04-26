#include <iostream>
struct deck {
    int arr[1000000];
    int front;
    int rear;
    deck() {
        front = 0;
        rear = 0;
    }
    void pushFront(int value) {
        for (int i=rear - 1; i>=front; i--) {
            arr[i + 1] = arr[i];
        }
        rear++;
        arr[front] = value;
    }
    void pushBack(int value) {
        arr[rear++] = value;
    }
    int popFront() {
        if (empty())
            return -1;
        else
            return arr[front++];
    }
    int popBack() {
        if (empty())
            return -1;
        else
            return arr[--rear];
    }
    int size() {
        return rear - front;
    }
    bool empty () {
        return size() == 0;
    }
    int getFront() {
        if (empty()) {
            return -1;
        }
        else
            return arr[front];
    }
    int back() {
        if (empty())
            return -1;
        else
            return arr[rear - 1];
    }
};
int main() {
    int n;
    std::cin >> n;
    struct deck *d = new deck();
    int value;
    
    for (int i=0; i<n; i++) {
        std::string str;
        std::cin >> str;
        if (str == "push_front") {
            std::cin >> value;
            (*d).pushFront(value);
        } else if (str == "push_back") {
            std::cin >> value;
            (*d).pushBack(value);
        } else if (str == "pop_front") {
            std::cout << (*d).popFront() << "\n";
        } else if (str == "pop_back") {
            std::cout << (*d).popBack() << "\n";
        } else if (str == "size") {
            std::cout << (*d).size() << "\n";
        } else if (str == "empty") {
            std::cout << (*d).empty() << "\n";
        } else if (str == "front") {
            std::cout << (*d).getFront() << "\n";
        } else if (str == "back") {
            std::cout << (*d).back() << "\n";
        }
    }
    return 0;
}
    
