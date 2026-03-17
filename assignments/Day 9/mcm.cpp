#include <bits/stdc++.h>
using namespace std;

const long long INF = (1LL << 62);

string buildParenthesis(const vector<vector<int>> &split, int i, int j)
{
	if (i == j)
	{
		return "A" + to_string(i);
	}

	int k = split[i][j];
	return "(" + buildParenthesis(split, i, k) + " x " + buildParenthesis(split, k + 1, j) + ")";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	if (!cin || n <= 0)
	{
		cout << "Invalid input\n";
		return 0;
	}

	vector<long long> p(n + 1);
	for (int i = 0; i <= n; i++)
	{
		cin >> p[i];
	}

	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
	vector<vector<int>> split(n + 1, vector<int>(n + 1, -1));

	for (int len = 2; len <= n; len++)
	{
		for (int i = 1; i + len - 1 <= n; i++)
		{
			int j = i + len - 1;
			dp[i][j] = INF;

			for (int k = i; k < j; k++)
			{
				long long cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (cost < dp[i][j])
				{
					dp[i][j] = cost;
					split[i][j] = k;
				}
			}
		}
	}

	cout << dp[1][n] << "\n";
	cout << buildParenthesis(split, 1, n) << "\n";

	return 0;
}