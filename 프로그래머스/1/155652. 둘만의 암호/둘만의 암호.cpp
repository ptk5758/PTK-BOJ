#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    for (int i=0; i<s.length(); i++) {
        int c = s[i] % 96;
        int count = index;
        int temp = c;
        while (count--) {
            temp = (temp + 1) % 27;
            if (temp == 0) temp++;
            for (int j=0; j<skip.length(); j++) {
                int sc = skip[j] % 96;
                if (sc == temp) count++;
            }
            // cout << temp << " (" << cc << ") ";
        }
        char cc = temp + 96;
        answer += cc;
        // cout << "\n";
        
    }
    return answer;
}