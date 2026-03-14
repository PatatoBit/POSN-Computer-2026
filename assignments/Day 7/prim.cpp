#include <bits/stdc++.h>
using namespace std;

struct CompareWeights
{
	bool operator()(pair<int, int> const &a, pair<int, int> const &b)
	{
		return a.second > b.second;
	}
};

int main()
{
	vector<vector<pair<int, int>>> adj(8);

	auto addEdge = [&](int u, int v, int w)
	{
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	};

	addEdge(1, 2, 28);
	addEdge(1, 6, 10);
	addEdge(6, 5, 25);
	addEdge(5, 4, 22);
	addEdge(4, 3, 12);
	addEdge(2, 3, 16);
	addEdge(2, 7, 14);
	addEdge(7, 4, 18);
	addEdge(7, 5, 24);

	priority_queue<pair<int, int>, vector<pair<int, int>>, CompareWeights> pq;
	vector<bool> visited(8, false);
	pq.push({1, 0});

	int mst_weight = 0;

	while (!pq.empty())
	{
		pair<int, int> top = pq.top();
		pq.pop();

		int u = top.first;
		int weight = top.second;

		if (visited[u] == true)
			continue;

		visited[u] = true;
		mst_weight += weight;

		// For every neighbour of the visited node, if it's not visited, add to queue
		for (const auto &neighbour : adj[u])
		{
			if (visited[neighbour.first] == false)
				pq.push(neighbour);
		}
	}

	cout << "Total MST Weight: " << mst_weight << endl;

	return 0;
}