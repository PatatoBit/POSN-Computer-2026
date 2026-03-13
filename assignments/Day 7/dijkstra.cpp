#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n = 5;

	// node(neighbours(node, weight)...)
	vector<vector<pair<int, int>>> adj(n);

	adj[2].push_back({1, 2});
	adj[2].push_back({3, 7});
	adj[2].push_back({0, 6});
	adj[1].push_back({3, 3});
	adj[1].push_back({4, 6});
	adj[3].push_back({4, 5});
	adj[0].push_back({4, 1});

	vector<int> distance(n, INT_MAX);
	distance[2] = 0;

	// (distance, node)
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// source node
	pq.push({0, 2});

	while (!pq.empty())
	{
		pair<int, int> top = pq.top();
		pq.pop();
		int d = top.first, u = top.second;

		if (d > distance[u])
			continue;

		// For every neighbour at node[u]
		for (pair<int, int> v : adj[u])
		{
			int neighbour = v.first, weight = v.second;
			if (distance[u] + weight < distance[neighbour])
			{
				distance[neighbour] = distance[u] + weight;
				pq.push({distance[neighbour], neighbour});
			};
		}
	}

	cout << "Shortest distance" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "2 -> " << i << ": ";
		if (distance[i] == INT_MAX)
			cout << "INF" << endl;
		else
			cout << distance[i] << endl;
	}

	return 0;
}