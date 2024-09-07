#include <iostream>
#include <algorithm>

int main() {
    int *arr = new int[3];
    for (int i=0; i<3; i++) {
        std::cin >> arr[i];
    }
    std::sort(arr, arr + 3);
    for (int i=0; i<3; i++) {
        std::cout << arr[i] << " ";
    }
    
    delete [] arr;
    
}
