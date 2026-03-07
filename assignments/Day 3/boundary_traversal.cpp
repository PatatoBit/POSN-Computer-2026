/*
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
	vector<int> boundaryTraversal(Node *root)
	{
		// code here
		vector<int> output;

		// Root
		if (root->left || root->right)
		{
			output.push_back(root->data);
		}
		else
		{
			output.push_back(root->data);
			return output; // Only root exists
		}

		// Left boundary
		Node *curr = root->left;

		while (curr)
		{
			if (curr->left != NULL || curr->right != NULL)
				output.push_back(curr->data);

			if (curr->left)
				curr = curr->left;
			else
				curr = curr->right;
		}

		// Leaves
		stack<Node *> z;

		z.push(root);

		while (!z.empty())
		{
			curr = z.top();
			z.pop();

			if (curr->left == NULL && curr->right == NULL)
				output.push_back(curr->data);

			if (curr->right)
				z.push(curr->right);
			if (curr->left)
				z.push(curr->left);
		}

		// Right boundary
		curr = root->right;
		stack<int> s;

		while (curr)
		{
			if (curr->left != NULL || curr->right != NULL)
				s.push(curr->data);

			if (curr->right)
				curr = curr->right;
			else
				curr = curr->left;
		}

		while (s.size() != 0)
		{
			output.push_back(s.top());
			s.pop();
		}

		return output;
	}
};