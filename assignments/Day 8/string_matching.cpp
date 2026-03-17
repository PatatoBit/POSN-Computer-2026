#include <bits/stdc++.h>
using namespace std;

vector<int> rabinKarp(const string &text, const string &pattern)
{
	const long long MOD = 1000000007LL;
	const long long BASE = 911382323LL;

	int n = (int)text.size();
	int m = (int)pattern.size();
	vector<int> matches;

	if (m == 0 || m > n)
		return matches;

	long long patternHash = 0;
	long long windowHash = 0;
	long long highestPower = 1;

	for (int i = 0; i < m; i++)
	{
		patternHash = (patternHash * BASE + (unsigned char)pattern[i]) % MOD;
		windowHash = (windowHash * BASE + (unsigned char)text[i]) % MOD;
		if (i < m - 1)
			highestPower = (highestPower * BASE) % MOD;
	}

	for (int i = 0; i <= n - m; i++)
	{
		if (windowHash == patternHash)
		{
			if (text.compare(i, m, pattern) == 0)
				matches.push_back(i);
		}

		if (i < n - m)
		{
			long long removeValue = ((unsigned char)text[i] * highestPower) % MOD;
			windowHash = (windowHash - removeValue + MOD) % MOD;
			windowHash = (windowHash * BASE + (unsigned char)text[i + m]) % MOD;
		}
	}

	return matches;
}

int main()
{
	string pattern, text;
	cin >> pattern >> text;

	vector<int> ans = rabinKarp(text, pattern);

	if (ans.empty())
	{
		cout << -1 << '\n';
	}
	else
	{
		for (int idx : ans)
			cout << idx << ' ';
		cout << '\n';
	}

	return 0;
}