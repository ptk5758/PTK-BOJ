#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for (int i=1; i<food.size(); i++) {        
        int count = food[i] / 2;
        int j;
        for (j=0; j<count; j++) {
            answer += to_string(i);
        }
    }
    answer += "0";    
    for (int i = answer.length() - 2; i >= 0; i--) {
        answer += answer[i];
        // cout << answer[i];
    }
    return answer;
}