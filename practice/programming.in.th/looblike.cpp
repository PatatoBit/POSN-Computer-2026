// https://programming.in.th/tasks/0033

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, max = 0;
	cin >> n;

	vector<int> dict(10001, 0);

	while (n--)
	{
		int x;
		cin >> x;

		dict[x]++;

		if (dict[x] > max)
			max = dict[x];
	}

	for (int i = 0; i < dict.size(); i++)
	{
		if (dict[i] == max)
			cout << i << " ";
	}

	return 0;
}