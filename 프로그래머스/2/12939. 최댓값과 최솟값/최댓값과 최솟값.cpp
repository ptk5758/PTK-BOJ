#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

string split(string input, char delimiter) {
    // vector<string> answer;
    int max = -999999999;
    int min = 999999999;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimiter)) {
        int value = stoi(temp);
        cout << value;
        if (max < value)
            max = value;
        if (min > value)
            min = value;
    }
    // cout << "MAX : " << max << "\nMIN : " << min;
    string answer = to_string(min) + " " + to_string(max);
    
    return answer;
    
}
string solution(string s) {
    string answer = split(s, ' ');
    return answer;
}