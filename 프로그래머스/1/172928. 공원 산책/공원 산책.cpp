#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;
struct direction {
    int x;
    int y;
};
vector<string> split(string input, char dlim) {
    vector<string> result;
    
    stringstream ss;
    string stringBuffer;
    ss.str(input);
    
    while (getline(ss, stringBuffer, dlim)) {
        result.push_back(stringBuffer);
    }
    return result;
}
vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    vector<vector<bool>> board;
    direction start;    
    int weight = 0;
    int height = 0;
    map<char, direction> directionMap = 
    {
        {
            'N', {0, -1}
        },
        {
            'S', {0, 1}
        },
        {
            'W', {-1, 0}
        },
        {
            'E', {1, 0}
        },
    };
    for (int i=0; i<park.size(); i++, height++) {
        string str = park[i];
        vector<bool> line;
        for (int j=0; j<str.length(); j++) {
            weight = str.size();
            char c = str[j];
            if (c == 'X') {
                line.push_back(false);
            } else {
                line.push_back(true);
                if (c == 'S') start = {j, i};
            }
        }
        board.push_back(line);
    }
    // cout << "HEIGHT : " << height << " WEIGHT : " << weight;
    for (int i=0; i<routes.size(); i++) {
        vector<string> str = split(routes[i], ' ');
        direction direction = directionMap[str[0][0]];        
        int count = stoi(str[1]);        
        int nx = start.x;
        int ny = start.y;
        bool flag = true;
        for (int j=0; j<count; j++) {
            nx += direction.x;
            ny += direction.y;
            if (0 > nx || nx >= weight) {
                flag = false;
                break;
            }
            if (0 > ny || ny >= height) {
                flag = false;
                break;
            }
            if (!board[ny][nx]) {
                flag = false;
                break;
            }
            // cout << "NY : " << ny << " NX : " << nx << " 값 => " << board[ny][nx] << "\n";
        }        
        if (flag) {
            start.x = nx;
            start.y = ny;
        }
        // cout << "=========\n";
    }
    answer.push_back(start.y);
    answer.push_back(start.x);
    
    return answer;
}