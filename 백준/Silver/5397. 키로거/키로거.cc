#include <iostream>
#include <string>

struct Node
{
	char data;
	Node* prev;
	Node* next;
	Node(char value) {
		data = value;
		prev = nullptr;
		next = nullptr;
	}
};
void Solve()
{
	std::string str; std::cin >> str;
	Node* current = new Node('_'), *begin = current;
	for (int i = 0; i < str.size(); i++)
	{
		char c = str[i];
		bool isOperator = c == '<' || c == '>' || c == '-';
		if (isOperator) {
			/*std::cout << "현재 커서 위치 :" << current->data;*/
			if (c == '<') {
				if (current->prev != nullptr) {
					current = current->prev;
				}
			} else if (c == '>') {
				if (current->next != nullptr) {
					current = current->next;
				}
			} else if (c == '-') {
				if (current->prev != nullptr) {
					if (current->next != nullptr) {
						current->prev->next = current->next;
						current->next->prev = current->prev;
						current = current->prev;
					} else {
						current->prev->next = nullptr;
						current = current->prev;
					}
				}
			}
			/*std::cout << " 변경 이후 : " << current->data << "\n";*/
		} else {
			Node* node = new Node(c);
			if (current == nullptr) {				
				current = node;
				begin = node;
				continue;
			}
			node->prev = current;
			if (current->next != nullptr) {
				node->next = current->next;
				current->next->prev = node;
			}
			current->next = node;
			current = node;
		}
	}
	begin = begin->next;
	while (begin != nullptr)
	{
		std::cout << begin->data;
		begin = begin->next;
	}
	std::cout << "\n";
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n; std::cin >> n;
	while (n--) Solve();
	return 0;
}