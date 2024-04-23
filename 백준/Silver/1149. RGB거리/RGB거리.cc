#include <iostream>
int main() {
    // 입력
    int n;
    std::cin >> n;
    
    // 메모리 할당
    int **arr = new int*[3];
    int **d = new int*[3];
    for (int i=0; i<3; i++) {
        arr[i] = new int[n];
        d[i] = new int[n] {0,};
    }
//    int arr[3][1001];
//    int d[3][1001];
    
    // 값 삽입
    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            std::cin >> arr[j][i];
            if (i == 0) {
                d[j][i] = arr[j][i];
            }
        }
    }
    for (int i=1; i<n; i++) {
        d[0][i] = (d[1][i-1] > d[2][i-1] ? d[2][i-1] : d[1][i-1]) + arr[0][i];
        d[1][i] = (d[0][i-1] > d[2][i-1] ? d[2][i-1] : d[0][i-1]) + arr[1][i];
        d[2][i] = (d[0][i-1] > d[1][i-1] ? d[1][i-1] : d[0][i-1]) + arr[2][i];
    }
    if (d[0][n-1] > d[1][n-1]) {
        if (d[1][n-1] > d[2][n-1]) {
            std::cout << d[2][n-1];
        } else {
            std::cout << d[1][n-1];
        }
    } else {
        if (d[0][n-1] > d[2][n-1]) {
            std::cout << d[2][n-1];
        } else {
            std::cout << d[0][n-1];
        }
    }
    
    // 메모리 헤제
    for (int i=0; i<3; i++) {
        delete [] arr[i];
        delete [] d[i];
    }
    delete [] arr;
    delete [] d;
    
    return 0;
}
