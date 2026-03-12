#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	int freq;
	Node *left, *right;

	Node(char data, int freq)
	{
		left = right = nullptr;
		this->data = data;
		this->freq = freq;
	}
};

// Sort pair value for pq
struct compare
{
	bool operator()(Node *l, Node *r)
	{
		return (l->freq > r->freq);
	}
};

void printCodes(Node *root, string str)
{
	if (!root)
		return;

	// If leaf node, print character
	if (root->data != '$')
		cout << root->data << ": " << str << "\n";

	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

int main()
{
	vector<pair<char, int>> freq = {
			{'f', 5},
			{'e', 9},
			{'c', 12},
			{'b', 13},
			{'d', 16},
			{'a', 45}};

	priority_queue<Node *, vector<Node *>, compare> pq;

	for (auto f : freq)
		pq.push(new Node(f.first, f.second));

	while (!pq.empty())
	{
		Node *left = pq.top();
		pq.pop();
		Node *right = pq.top();
		pq.pop();

		// New sum node
		Node *top = new Node('$', left->freq + right->freq);

		top->left = left;
		top->right = right;
		pq.push(top);
	}

	Node *root = pq.top();
	printCodes(root, "");

	return 0;
}