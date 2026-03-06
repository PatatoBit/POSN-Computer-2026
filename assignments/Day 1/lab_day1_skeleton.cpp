#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int v) : val(v), next(NULL) {}
};

Node *buildList(const vector<int> &v)
{
    Node *head = NULL;
    Node *tail = NULL;

    for (int x : v)
    {
        Node *temp = new Node(x);
        if (!head)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

void printList(Node *head)
{
    cout << "[";
    bool first = true;
    while (head)
    {
        if (!first)
            cout << ",";
        cout << head->val;
        first = false;
        head = head->next;
    }
    cout << "]\n";
}

// ===== TODO: Implement these functions =====
Node *reverseList(Node *head)
{
    // TODO
    Node *cur = head, *prev = nullptr, *next;

    while (cur != nullptr)
    {
        next = cur->next;

        cur->next = prev;

        prev = cur;
        cur = next;
    }

    return prev;
}

Node *removeValue(Node *head, int X)
{
    // TODO
    Node dummy(0);
    dummy.next = head;

    Node *prev = &dummy;
    Node *cur = head;

    while (cur)
    {
        if (cur->val == X)
        {
            Node *toDelete = cur;
            prev->next = cur->next;
            cur = cur->next;
            delete toDelete;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }

    return dummy.next;
}

Node *mergeList(Node *a, Node *b)
{
    // TODO
    Node dummy(0);
    Node *tail = &dummy;

    while (a && b)
    {
        if (a->val <= b->val)
        {
            tail->next = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            b = b->next;
        }

        tail = tail->next;
    }

    if (a)
    {
        tail->next = a;
    }
    else if (b)
    {
        tail->next = b;
    }

    return dummy.next;
}

// ===== Simple local tests (optional) =====
int main()
{
    // Level 1 test
    Node *h1 = buildList({1, 2, 3, 4});
    h1 = reverseList(h1);
    printList(h1); // expected [4,3,2,1]

    // Level 2 test
    Node *h2 = buildList({1, 2, 3, 2, 4, 2});
    h2 = removeValue(h2, 2);
    printList(h2); // expected [1,3,4]

    // Level 3 test
    Node *a = buildList({1, 2, 4});
    Node *b = buildList({1, 3, 4});
    Node *m = mergeList(a, b);
    printList(m); // expected [1,1,2,3,4,4]

    return 0;
}
