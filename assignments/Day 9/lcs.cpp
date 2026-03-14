#include <bits/stdc++.h>
using namespace std;

// void printVector(const vector<vector<int>> &v)
// {
// 	for (auto row : v)
// 	{
// 		for (auto col : row)
// 		{
// 			cout << col << " ";
// 		}

// 		cout << endl;
// 	}
// }

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	vector<vector<int>> memo(s1.length() + 1, vector<int>(s2.length() + 1, 0));

	for (int i = 1; i <= s1.length(); i++)
	{
		for (int j = 1; j <= s2.length(); j++)
		{
			if (s1[i - 1] == s2[j - 1])
				memo[i][j] = memo[i - 1][j - 1] + 1;
			else
				memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
		}
	}

	cout << memo[s1.length()][s2.length()];

	return 0;
}