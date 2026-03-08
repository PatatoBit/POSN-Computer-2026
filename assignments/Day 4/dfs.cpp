class Solution
{
public:
	vector<int> dfs(vector<vector<int>> &adj)
	{
		// Code here
		vector<int> output;
		int n = adj.size();

		stack<int> s;
		s.push(0);
		vector<bool> visited(n, false);

		while (!s.empty())
		{
			int node = s.top();
			s.pop();

			// If current node is not visited, print and mark visited
			if (!visited[node])
			{
				output.push_back(node);
				visited[node] = true;
			}

			vector<int> neighbours = adj[node];

			// Reverse for stack
			// Loop through neighbours (reversed)
			// If neighbour is not visited, add to stack
			for (int i = neighbours.size() - 1; i >= 0; i--)
			{
				if (!visited[neighbours[i]])
				{
					s.push(neighbours[i]);
				}
				else
					continue;
			}
		}

		return output;
	}
};