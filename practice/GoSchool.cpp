#include <bits/stdc++.h>
using namespace std;

void printVector(const vector<pair<int, int>> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << "(" << v[i].first << ", " << v[i].second << ")";

		if (i != v.size() - 1)
			cout << ", ";
	}

	cout << endl;
}

void printMap(const vector<vector<int>> &m)
{
	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m[i].size(); j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int w, h;
	cin >> w >> h;
	vector<vector<int>> memo(h, vector<int>(w));

	int n;
	cin >> n;

	vector<pair<int, int>> dogs(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		// cout << "X: " << x << endl;
		// cout << "Y: " << y << endl;
		// cout << "(" << h - y << ", " << x - 1 << ")\n\n";

		dogs[i] = {h - y, x - 1};
	}

	// printVector(dogs);

	// Fill bottom row
	for (int i = 0; i < w; i++)
	{
		pair<int, int> finder = make_pair(h - 1, i);
		auto it = find(dogs.begin(), dogs.end(), finder);

		if (it != dogs.end())
			memo[h - 1][i] = 0;
		else if (it == dogs.end() && i == 0)
			memo[h - 1][i] = 1;
		else
			memo[h - 1][i] = memo[h - 1][i - 1];
	}

	// Fill first column
	for (int i = h - 1; i >= 0; i--)
	{
		pair<int, int> finder = make_pair(i, 0);
		auto it = find(dogs.begin(), dogs.end(), finder);

		if (it != dogs.end())
			memo[i][0] = 0;
		else if (it == dogs.end() && i == h - 1)
			memo[i][0] = 1;
		else
			memo[i][0] = memo[i + 1][0];
	}

	int index = 1;

	// Traverse
	for (int i = h - 2; i >= 0; i--)
	{
		for (int j = 1; j < w; j++)
		{
			pair<int, int> finder = make_pair(i, j);
			auto it = find(dogs.begin(), dogs.end(), finder);

			// If dog
			if (it != dogs.end())
				memo[i][j] = 0;
			else
				memo[i][j] = memo[i + 1][j] + memo[i][j - 1];
		}
	}

	// printMap(memo);
	cout << memo[0][w - 1];

	return 0;
}