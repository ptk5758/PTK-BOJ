#include <iostream>

struct minHeap {
    int *arr;
    minHeap (int size) {
        arr = new int[size];
        length = 0;
    }
    void insert (int value) {
        arr[length++] = value;
        int start = length - 1;
        while (start > 0) {
            int parent = (start - 1) / 2;
            if (arr[parent] > arr[start]) {
                int temp = arr[parent];
                arr[parent] = arr[start];
                arr[start] = temp;
            } else {
                break;
            }
            start = parent;
        }
    }
    void heapify(int i) {
        int target = i;
        int left = target * 2 + 1;
        int right = target * 2 + 2;
        if (left < length && arr[target] > arr[left]) {
            target = left;
        }
        if (right < length && arr[target] > arr[right]) {
            target = right;
        }
        if (target != i) {
            int temp = arr[i];
            arr[i] = arr[target];
            arr[target] = temp;
            heapify(target);
        }
    }
    bool empty () {
        return length == 0;
    }
    ~minHeap () {
        delete [] arr;
    }
    int length;
};

struct maxHeap {
    int *arr;
    maxHeap (int size) {
        arr = new int[size];
        length = 0;
    }
    void insert (int value) {
        arr[length++] = value;
        int start = length - 1;
        while (start > 0) {
            int parent = (start - 1) / 2;
            if (arr[parent] < arr[start]) {
                int temp = arr[parent];
                arr[parent] = arr[start];
                arr[start] = temp;
            } else {
                break;
            }
            start = parent;
        }
    }
    void heapify(int i) {
        int target = i;
        int left = target * 2 + 1;
        int right = target * 2 + 2;
        if (left < length && arr[target] < arr[left]) {
            target = left;
        }
        if (right < length && arr[target] < arr[right]) {
            target = right;
        }
        if (target != i) {
            int temp = arr[i];
            arr[i] = arr[target];
            arr[target] = temp;
            heapify(target);
        }
    }
    bool empty () {
        return length == 0;
    }
    ~maxHeap () {
        delete [] arr;
    }
    int length;
};
int main() {
    // 환경 설정
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    // 초기화
    int n;
    std::cin >> n;
    minHeap minH(n / 2 + 1);
    maxHeap maxH(n / 2 + 1);
    
    // Service
    for (int i=0; i<n; i++) {
        int value;
        std::cin >> value;
        if (i % 2 == 0) {
            maxH.insert(value); // 5, 15
        } else {
            minH.insert(value); // 10, 20
        }
        
        if (!minH.empty() && minH.arr[0] < maxH.arr[0]) {
            int temp = minH.arr[0];
            minH.arr[0] = maxH.arr[0];
            maxH.arr[0] = temp;
            minH.heapify(0);
            maxH.heapify(0);
        }
        
        std::cout << maxH.arr[0] << "\n";
    }
    
    
    return 0;
}
