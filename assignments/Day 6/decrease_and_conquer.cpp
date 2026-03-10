#include <bits/stdc++.h>
using namespace std;

int pow(int a, int n)
{
	if (n == 1)
		return a;

	return a * pow(a, n - 1);
}

int main()
{
	int a, n;
	cin >> a >> n;

	cout << pow(2, 5);

	return 0;
}