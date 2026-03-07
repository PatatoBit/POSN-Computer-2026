/*
// Tree Node
class Node {
		public:
				int data;
				Node* left;
				Node* right;

				// Constructor to initialize a new node
				Node(int val) {
								data = val;
								left = NULL;
								right = NULL;
				}
};
*/

class Solution
{
public:
	int getCount(Node *root, int l, int h)
	{
		// your code here

		stack<Node *> s;
		s.push(root);

		int sum = 0;

		while (!s.empty())
		{
			Node *curr = s.top();
			s.pop();

			if (curr->data >= l && curr->data <= h)
			{
				sum += 1;
			}

			if (curr->right)
				s.push(curr->right);
			if (curr->left)
				s.push(curr->left);
		}

		return sum;
	}
};