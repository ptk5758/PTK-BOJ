#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<int> vec;
    for (int i=0; i<6; i++) {
        int value;
        std::cin >> value;
        vec.push_back(value);
    }
    int t, p; std::cin >> t >> p;
    int count = 0;
    for (int i=0; i<vec.size(); i++) {
        if (vec[i] == 0) continue;
        count += vec[i] / t;
        if (vec[i] % t != 0) count++;
    }
    std::cout << count << "\n";
    std::cout << n / p << " " << n % p << "\n";
}
