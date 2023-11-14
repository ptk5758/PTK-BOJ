#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    queue<char> que;
    for (int i=0; i<s.length(); i++) {
        que.push(s[i]);
    }
    int count = 0;
    char target = que.front();
    while (!que.empty()) {
        char c = que.front();
        que.pop();
        if (target == c) {
            count++;
        } else {
            count--;
        }
        if (count == 0) {
            target = que.front();
            answer++;
        }
    }
    if (count != 0) answer++;
    
    return answer;
}