#include <bits/stdc++.h>
using namespace std;

struct Edge
{
	int u;
	int v;
	int weight;
};

int main()
{
	// n of edges
	int m = 10, n = 8;
	vector<Edge> edges = {
			{1, 2, 6},
			{1, 3, 5},
			{1, 4, 5},
			{2, 5, -1},
			{3, 2, -2},
			{3, 5, 1},
			{4, 3, -2},
			{4, 6, -1},
			{5, 7, 3},
			{6, 7, 3}};

	// init
	vector<int> distance(n, INT_MAX);
	distance[1] = 0;

	for (int i = 1; i <= n - 1; i++)
	{
		for (auto e : edges)
		{
			if (distance[e.u] != INT_MAX && distance[e.u] + e.weight < distance[e.v])
			{
				distance[e.v] = distance[e.u] + e.weight;
			}
		}
	}

	bool hasNegativeCycle = false;
	for (auto e : edges)
	{
		if (distance[e.u] != INT_MAX && distance[e.u] + e.weight < distance[e.v])
		{
			hasNegativeCycle = true;
			break;
		}
	}

	if (hasNegativeCycle)
	{
		cout << "Graph has negative cycle" << endl;
	}

	if (!hasNegativeCycle)
	{
		cout << "Node\tDistance from 1" << endl;
		for (int i = 1; i <= n; i++)
		{
			cout << i << "\t";
			if (distance[i] == INT_MAX)
				cout << "INF" << endl;
			else
				cout << distance[i] << endl;
		}
	}

	return 0;
}