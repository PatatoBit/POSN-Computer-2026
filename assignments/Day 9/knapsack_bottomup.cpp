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

int knapsack(int n, int W, vector<int> &values, vector<int> &weights)
{
	vector<vector<int>> output(n + 1, vector<int>(W + 1, 0));

	// For every item
	for (int i = 1; i <= n; i++)
	{
		// For every capacity
		for (int j = 1; j <= W; j++)
		{
			if (weights[i - 1] <= j)
				output[i][j] = max(output[i - 1][j], values[i - 1] + output[i - 1][j - weights[i - 1]]);
			else
				output[i][j] = output[i - 1][j];
		}
	}

	return output[n][W];
}

int main()
{
	int W, n;
	cin >> W >> n;

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