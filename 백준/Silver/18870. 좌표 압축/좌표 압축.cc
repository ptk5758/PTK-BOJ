#include <iostream>
#include <algorithm>
#include <map>
#include <set>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n; std::cin >> n;
    int* arr = new int [n];
    std::map<int, int> map;
    
    for (int i=0; i<n; i++) std::cin >> arr[i];

    int* copy = new int [n];
    std::copy(arr, arr + n, copy);

    std::set<int> s(arr, arr + n);
    int i=0;
    for (std::set<int>::iterator iter = s.begin(); iter != s.end(); iter++, i++) 
    {
        map.insert({*iter, i});
    }


    for (int i=0; i<n; i++)
    {
        std::cout << map[copy[i]] << " ";
    }
    std::cout << "\n";
    return 0;
}