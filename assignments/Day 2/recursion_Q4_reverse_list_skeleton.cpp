
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// TODO: Implement recursive reverse
Node *reverseList(Node *head)
{
    // base case?
    if (head->next == NULL || !head)
        return head;
    // recursive call?
    Node *newHead = reverseList(head->next);
    // pointer adjustment?
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

void printList(Node *head)
{
    Node *cur = head;
    while (cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main()
{

    // create example list: 1 -> 2 -> 3 -> 4
    Node *head = new Node{1, NULL};
    head->next = new Node{2, NULL};
    head->next->next = new Node{3, NULL};
    head->next->next->next = new Node{4, NULL};

    cout << "Original list: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}
