#include <iostream>
#include <string>
#include <map>

void solve(int n);
int main() {
    // 기본 입 출력 설정
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    // T Case, Data 갯수 N
    // 반복
    int n,t;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        solve(n);
    }
    return 0;
}

void solve(int n) {
    // 같은 카테고리 의류 분류
    std::map<std::string, int> map;
    
    int result = 1;
    for (int i=0; i<n; i++) {
        
        // 데이터 입력
        std::string value, key;
        std::cin >> value >> key;
        map[key]++;
    }
    
    
    // 모든 KEY를 순회하며 Result에 조합의 수 곱함
    for (std::pair<std::string, int> p : map) {
        result *= p.second + 1;
    }
    
    // 출력
    std::cout << (result - 1) << "\n";
}
