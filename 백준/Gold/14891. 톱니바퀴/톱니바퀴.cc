#include <iostream>
#include <string>
#include <deque>
#include <queue>
#include <tuple>
#include <set>


typedef std::deque<bool> List;
typedef std::set<int> History;
typedef std::tuple<int, int, History> Action; // index, direction
typedef std::queue<Action> Queue;

int main()
{
	List items[4];
	for (int i = 0; i < 4; i++) {
		std::string str; std::cin >> str;
		List item;
		for (int j = 0; j < str.size(); j++) {
			int value = str[j] - '0';
			item.push_back(value == 1 ? true : false);
		}
		items[i] = item;
	}
	int n; std::cin >> n;
	while (n--) 
	{
		int itemIndex, direciton; std::cin >> itemIndex >> direciton;
		itemIndex--;
		Queue queue;
		History history;
		history.insert(itemIndex);
		queue.push({ itemIndex, direciton, history });
		while (!queue.empty())
		{
			Action action = queue.front();
			queue.pop();
			int currentIndex = std::get<0>(action);
			int currentDirection = std::get<1>(action);
			History currentHistory = std::get<2>(action);
			List item = items[currentIndex];
			currentHistory.insert(currentIndex);
			if (currentIndex != 0) {
				if (currentHistory.count(currentIndex - 1) == 0 && items[currentIndex - 1][2] != item[6]) {
					queue.push({ currentIndex - 1, currentDirection * -1, currentHistory});
				}
			}

			if (currentIndex != 3) {
				if (currentHistory.count(currentIndex + 1) == 0 && items[currentIndex + 1][6] != item[2]) {
					queue.push({ currentIndex + 1, currentDirection * -1, currentHistory });
				}
			}

			if (currentDirection == 1) { // 시계
				item.push_front(item.back());
				item.pop_back();
			} else { // 반 시계
				item.push_back(item.front());
				item.pop_front();
			}
			items[currentIndex] = item;
		}
		
	}
	int p[4] = { 1, 2, 4, 8 };
	int result = 0;
	for (int i = 0; i < 4; i++) {
		if (items[i][0] == true) {
			result += p[i];
		}
	}
	std::cout << result << "\n";
	return 0;
}