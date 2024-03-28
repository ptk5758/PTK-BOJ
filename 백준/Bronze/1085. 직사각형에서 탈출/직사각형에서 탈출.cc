#include <iostream>

int main() {
    int x, y, width, height;
    std::cin >> x >> y >> width >> height;
    int horizontalMid = width / 2;
    int verticalMid = height / 2;
    int xDistant = x > horizontalMid ? width - x : x;
    int yDistant = y > verticalMid ? height - y : y;
    std::cout << (xDistant > yDistant ? yDistant : xDistant);
    return 0;
}
