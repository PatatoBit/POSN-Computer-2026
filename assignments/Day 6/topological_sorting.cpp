#include <bits/stdc++.h>
using namespace std;

int main()
{
	// 1-based adjacency list for nodes 1..9.
	vector<vector<int>> graph = {
			{},
			{2, 3, 5},
			{4, 5},
			{5, 6},
			{7},
			{6, 7, 9},
			{8},
			{9},
			{7, 9},
			{}};

	int n = 9;
	vector<int> indegree(n + 1, 0);

	for (int u = 1; u <= n; u++)
	{
		for (int v : graph[u])
		{
			indegree[v]++;
		}
	}

	queue<int> q;
	for (int node = 1; node <= n; node++)
	{
		if (indegree[node] == 0)
		{
			q.push(node);
		}
	}

	vector<int> topo_order;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		topo_order.push_back(u);

		for (int v : graph[u])
		{
			indegree[v]--;
			if (indegree[v] == 0)
			{
				q.push(v);
			}
		}
	}

	if ((int)topo_order.size() != n)
	{
		cout << "graph has a cycle";
		return 0;
	}

	for (int node : topo_order)
	{
		cout << node << ' ';
	}
	cout << '\n';

	return 0;
}