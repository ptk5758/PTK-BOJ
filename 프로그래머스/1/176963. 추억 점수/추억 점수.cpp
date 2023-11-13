#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> yearningMap;
    for (int i=0; i<yearning.size(); i++) {
        yearningMap.insert({name[i], yearning[i]});
    }
    for (int i=0; i<photo.size(); i++) {
        vector<string> arr = photo[i];
        int point = 0;
        for (int j=0; j<arr.size(); j++) {
            point += yearningMap[arr[j]];
            // cout << yearningMap[arr[j]] << " ";
        }
        answer.push_back(point);
    }
    return answer;
}