#include <bits/stdc++.h>
using namespace std;

void dfs(int node, const vector<vector<int>> &adj, vector<int> &visited, vector<int> &component)
{
	visited[node] = 1;
	component.push_back(node);

	for (int next : adj[node])
	{
		if (!visited[next])
		{
			dfs(next, adj, visited, component);
		}
	}
}

int main()
{
	vector<vector<int>> adj = {{1}, {0, 2, 3}, {1, 3}, {1, 4}, {3}, {}, {7, 8}, {6}, {6}};
	vector<int> visited(adj.size());
	vector<vector<int>> components;

	for (int i = 0; i < (int)adj.size(); i++)
	{
		if (!visited[i])
		{
			vector<int> component;
			dfs(i, adj, visited, component);
			components.push_back(component);
		}
	}

	cout << "Number of connected components: " << components.size() << "\n";
	for (int i = 0; i < (int)components.size(); i++)
	{
		cout << i + 1 << ": ";
		for (int node : components[i])
		{
			cout << node << ' ';
		}
		cout << "\n";
	}

	return 0;
}