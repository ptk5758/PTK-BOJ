#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct student {
    std::string name;
    int birth[3];
};
bool compare(student &a, student &b) {
    if (a.birth[2] > b.birth[2]) {
        return true;
    } else if (a.birth[2] == b.birth[2]) {
        if (a.birth[1] > b.birth[1]) {
            return true;
        } else if (a.birth[1] == b.birth[1]) {
            if (a.birth[0] > b.birth[0]) {
                return true;
            } else {
                return false;
            }
            
        } else {
            return false;
        }
    } else {
        return false;
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n; std::cin >> n;
    std::vector<student> vec(n);
    for (int i=0; i<n; i++)
    {
        std::cin >> vec[i].name >> vec[i].birth[0] >> vec[i].birth[1] >> vec[i].birth[2];
    }
    std::sort(vec.begin(), vec.end(), compare);
    std::cout << vec[0].name << "\n";
    std::cout << vec[n - 1].name << "\n";
    return 0;
}
