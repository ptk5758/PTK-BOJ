#include <string>
#include <vector>
#include <iostream>

std::vector<int> solution(std::string s) {
    std::vector<int> answer;
    // std::cout << s.length();
    for (int i=0; i<s.length(); i++) {
        char target = s[i];
        int distance = -1;
        for (int j=0; j<=i; j++) {
            char c = s[j];
            if (i != j) {
                if (target == c)
                    distance = i - j;
            }
        }
        answer.push_back(distance);
    }
    return answer;
}