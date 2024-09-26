#include <iostream>
#include <map>
#include <vector>
#define SUCCESS "Possible"
#define FAILED "Impossible"
bool Solve() {
    char *l = new char [1001];
    char *r = new char [1001];
    
    std::map<char, int> wordMap;
    std::cin >> l >> r;
    
    for (int i=0; l[i] != '\0'; i++) {
        wordMap[l[i]]++;
    }
    
    for (int i=0; r[i] != '\0'; i++) {
        wordMap[r[i]]--;
    }
    
    for (char i = 'a'; i <= 'z'; i++) {
        if (wordMap[i] != 0) return false;
    }
    
    delete [] l;
    delete [] r;
    
    return true;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int t; std::cin >> t;
    while (t--) {
        if (Solve()) {
            std::cout << SUCCESS << "\n";
        } else {
            std::cout << FAILED << "\n";
        }
    }
    return 0;
}
