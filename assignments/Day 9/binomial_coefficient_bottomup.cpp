#include <bits/stdc++.h>
using namespace std;

int bino(int n, int k)
{
	vector<vector<int>> memo(n + 1, vector<int>(k + 1));

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= min(i, k); j++)
		{
			if (j == 0 || j == i)
				memo[i][j] = 1;
			else
				memo[i][j] = memo[i - 1][j - 1] + memo[i - 1][j];
		}
	}

	return memo[n][k];
}

int main()
{
	int n, k;
	cin >> n >> k;

	cout << bino(n, k);

	return 0;
}