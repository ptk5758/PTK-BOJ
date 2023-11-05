#include <vector>
#include <iostream>

std::vector<int> solution(std::vector<int> arr) 
{
    std::vector<int> answer;
    for (int i=0; i<arr.size(); i++) {
        int value = arr[i];
        // if (answer.back() != value) answer.push_back(value);
        if (answer.size() == 0) {
            answer.push_back(value);
        } else {
            if (answer.back() != value) 
                answer.push_back(value);
        }
        
    }
    return answer;
}