#include <iostream>
#include <vector>

struct Node
{
    int data;
    Node* next;    
    Node() {
        this->next = nullptr;
    }
};

int main()
{
    int n,k; std::cin >> n >> k;
    Node *list = new Node [n];
    for (int i=0; i<n; i++)
    {
        (list + i)->data = i + 1;
        if (i + 1 == n) {
            (list + i)->next = list + 0;
        } else {
            (list + i)->next = list + (i + 1);
        }
    }
    Node *head = list + n - 1;
    int count = n;
    std::cout << "<";
    while (count > 0) {
        for (int i=0; i<k - 1; i++)
        {
            head = head->next;
        }
        
        if (count == 1) {
            std::cout << head->next->data << ">";
        } else {
            std::cout << head->next->data << ", ";
        }
        head->next = head->next->next;
        count--;
    }
    
    return 0;
}

// 1 2 4 5 6 7