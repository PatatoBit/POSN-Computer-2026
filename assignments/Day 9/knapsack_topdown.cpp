#include <bits/stdc++.h>
using namespace std;

void printVector(const vector<vector<int>> &v)
{
	for (auto row : v)
	{
		for (auto col : row)
		{
			cout << col << " ";
		}

		cout << endl;
	}
}

int T[1001][1001];
int knapsack(int n, int W, vector<int> &values, vector<int> &weights)
{
	if (n == 0 || W == 0)
		return 0;

	if (T[n][W] != -1)
		return T[n][W];

	if (weights[n - 1] <= W)
	{
		T[n][W] = max(knapsack(n - 1, W, values, weights), values[n - 1] + knapsack(n - 1, W - weights[n - 1], values, weights));
	}
	else
	{
		T[n][W] = knapsack(n - 1, W, values, weights);
	}

	return T[n][W];
}

int main()
{
	int W, n;
	cin >> W >> n;
	memset(T, -1, sizeof(T));

	vector<int> values(n), weights(n);

	cout << "Enter " << n << " values: ";
	for (int i = 0; i < n; i++)
		cin >> values[i];

	cout << "Enter " << n << " weights: ";
	for (int i = 0; i < n; i++)
		cin >> weights[i];

	cout << knapsack(n, W, values, weights);

	return 0;
}