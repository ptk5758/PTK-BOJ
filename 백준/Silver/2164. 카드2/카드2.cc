#include <iostream>
#include <queue>
int main() {
    std::queue<int> deck;
    int count, i, num = 1;
    std::cin >> count;
    i = count;
    while(i--) deck.push(num++);
    while(deck.size() > 1) {
        deck.pop();
        deck.push(deck.front());
        deck.pop();
    }
    std::cout << deck.front() << "\n";
}
