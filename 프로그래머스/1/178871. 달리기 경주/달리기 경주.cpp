#include <string>
#include <vector>
#include <iostream>
#include <map>

std::vector<std::string> solution(std::vector<std::string> players, std::vector<std::string> callings) {
    std::vector<std::string> answer;
    std::map<std::string, int> map;
    for (int i=0; i<players.size(); i++) {
        map.insert(std::make_pair(players[i], i));
    }
    for (int i=0; i<callings.size(); i++) {
        int order = map[callings[i]];
        std::string temp = players[order-1];
        players[order-1] = players[order];
        players[order] = temp;
        map[callings[i]] = order-1;
        map[temp] = order;        
    }
    

    return players;
}