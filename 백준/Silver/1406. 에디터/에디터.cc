#include <iostream>
template <typename T>
struct LinkedList {
	T data;
	LinkedList<T> *prev;
	LinkedList<T> *next;
	LinkedList(T data) {
		this->data = data;
		prev = nullptr;
		next = nullptr;
	}
};
LinkedList<char>* CreateLinkedList(char *line) {
	int index = 0;
	LinkedList<char> *result = new LinkedList<char>(line[index++]);
	while (line[index] != '\0') {
		LinkedList<char> *node = new LinkedList<char>(line[index++]);
		result->next = node;
		node->prev = result;
		result = node;
	}
	return result;
}
void PrintList(LinkedList<char> *node) {
	LinkedList<char> *current = node;
	while (true) {
		if (current->data == '_') {
			break;
		}
		std::cout << current->data << "";
		if (current->next != nullptr) {
			current = current->next;
		} else {
			break;
		}
	}
}

void Solve() {
	char line[100001]; std::cin >> line;
	LinkedList<char> *head = CreateLinkedList(line),
		*current,
		*temp = new LinkedList<char>('_');
	temp->prev = head;
	head->next = temp;
	head = head->next;
	current = temp;
	int n; std::cin >> n;
	while (n--) {
		char c; std::cin >> c;
		if (c == 'L') {
			if (current->prev != nullptr) { current = current->prev; }
		} else if (c == 'D') {
			if (current->next != nullptr) { current = current->next; }
		} else if (c == 'B') {
			if (current->prev != nullptr) {
				LinkedList<char> *prevNode = current->prev;
				if (prevNode->prev != nullptr) {
					prevNode->prev->next = current;
					current->prev = prevNode->prev;
				} else {
					current->prev = nullptr;
				}
			}
		} else if (c == 'P') {
			char t; std::cin >> t;
			LinkedList<char> *node = new LinkedList<char>(t);
			if (current->prev != nullptr) {
				LinkedList<char>* prevNode = current->prev;
				prevNode->next = node;
				node->prev = prevNode;
			}
			node->next = current;
			current->prev = node;
		}
	}
	
	while (current->prev != nullptr) {
		current = current->prev;
	}
	PrintList(current);

}
int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	Solve();
	return 0;
}