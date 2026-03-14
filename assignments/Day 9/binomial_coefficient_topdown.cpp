#include <bits/stdc++.h>
using namespace std;

int bino(int n, int k, vector<vector<int>> &memo)
{
	if (k > n)
		return 0;

	if (k == 0 || k == n)
		return 1;

	if (memo[n][k] != -1)
		return memo[n][k];

	return memo[n][k] = bino(n - 1, k - 1, memo) + bino(n - 1, k, memo);
}

int main()
{
	int n, k;
	cin >> n >> k;

	vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));
	cout << bino(n, k, memo);

	return 0;
}