#include <bits/stdc++.h>
using namespace std;

struct DSU
{
	vector<int> parent;

	DSU(int n)
	{
		parent.resize(n + 1);
		for (int i = 0; i <= n; i++)
			parent[i] = i;
	}

	int find(int i)
	{
		if (parent[i] == i)
			return i;
		return parent[i] = find(parent[i]);
	}

	void unite(int i, int j)
	{
		int root_i = find(i);
		int root_j = find(j);
		if (root_i != root_j)
		{
			parent[root_i] = root_j;
		}
	}
};

struct Edge
{
	int u, v, weight;
};

bool compareEdge(Edge a, Edge b)
{
	return a.weight < b.weight;
}

int main()
{
	vector<Edge> edges = {
			{1, 2, 28},
			{1, 6, 10},
			{2, 3, 16},
			{2, 7, 14},
			{3, 4, 12},
			{4, 5, 22},
			{4, 7, 18},
			{5, 6, 25},
			{5, 7, 24},
	};

	sort(edges.begin(), edges.end(), compareEdge);

	DSU dsu(7);
	int mst_weight = 0;
	vector<Edge> mst_edges;

	for (Edge &e : edges)
	{
		if (dsu.find(e.u) != dsu.find(e.v))
		{
			dsu.unite(e.u, e.v);
			mst_weight += e.weight;
			mst_edges.push_back(e);
		}
	}

	cout << "All edges: \n";
	for (Edge &e : mst_edges)
	{
		cout << e.u << " - " << e.v << " : " << e.weight << endl;
	}
	cout << "\nTotal weight: " << mst_weight << endl;

	return 0;
}