#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &v)
{
	int r1 = 0, r2 = 0;

	for (auto n : v)
	{
		int temp = max(n + r1, r2);
		r1 = r2;
		r2 = temp;
	}

	return r2;
}

int main()
{
	int n;
	cin >> n;

	vector<int> v1, v2;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		if (i != 0)
			v1.push_back(x);

		if (i != n - 1)
			v2.push_back(x);
	}

	cout << max(rob(v1), rob(v2));
	return 0;
}