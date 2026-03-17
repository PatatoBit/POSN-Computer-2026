#include <bits/stdc++.h>
using namespace std;

int segi(int a, int b)
{
	if (a == 0 && b == 0)
		return 2;

	if (a == 0 && b == 1)
		return 1;

	if (a == 0 && b == 2)
		return 0;

	if (a == 1 && b == 0)
		return 2;

	if (a == 1 && b == 1)
		return 1;

	if (a == 1 && b == 2)
		return 1;

	if (a == 2 && b == 0)
		return 1;

	if (a == 2 && b == 1)
		return 2;

	if (a == 2 && b == 2)
		return 1;
}

int main()
{
	vector<vector<int>> v(20);
	vector<bool> output(20);

	for (int i = 0; i < 20; i++)
	{
		int n;
		cin >> n;
		vector<int> sequence(n);
		for (int i = 0; i < n; i++)
		{
			sequence.push_back(n);
		}
	}

	return 0;
}