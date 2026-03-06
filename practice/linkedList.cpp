#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int val;
	Node *next;
	Node(int v) : val(v), next(NULL) {};
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

Node *reversedList(Node *head)
{
	// TODO
	Node *curr = head, *prev = nullptr, *next;

	while (curr)
	{
		next = curr->next;

		curr->next = prev;

		prev = curr;
		curr = next;
	}

	return prev;
}

Node *filteredList(Node *head, int x)
{
	// TODO
	Node *curr = head, dummy = Node(0), *prev = &dummy;

	while (curr)
	{
		Node *next = curr->next;

		if (curr->val == x)
		{
			prev->next = next;
		}
		else
		{
			prev = curr;
		}

		curr = next;
	}

	return dummy->next;
}

Node *mergedList(Node *a, Node *b)
{
	Node *head;
	return head;
}

int main()
{
	Node *reversedDummy = buildList({1, 2, 3, 4});
	reversedDummy = reversedList(reversedDummy);
	printList(reversedDummy);

	Node *filterDummy = buildList({1, 2, 3, 3, 4, 5});
	filterDummy = filteredList(filterDummy, 1);
	printList(filterDummy);

	return 0;
}