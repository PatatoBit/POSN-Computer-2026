#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, n;
	cin >> a >> n;

	int output = a;
	for (int i = 0; i < n; i++)
	{
		cout << output << " ";
		output *= a;
	}

	return 0;
}