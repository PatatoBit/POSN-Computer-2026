#include <bits/stdc++.h>
using namespace std;

struct FenwickTree
{
	int n;
	vector<int> tree;
	FenwickTree(int n) : n(n), tree(n + 1, 0) {}

	void update(int i, int delta)
	{
		for (; i <= n; i += i & (-i))
			tree[i] += delta;
	}

	int query(int i)
	{
		int sum = 0;
		for (; i > 0; i -= i & (-i))
			sum += tree[i];
		return sum;
	}

	int query(int l, int r)
	{
		return query(r) - query(l - 1);
	}
};

int main()
{
	int m = 10;
	FenwickTree ft(m);

	vector<int> freq = {0, 0, 1, 0, 1, 2, 3, 2, 1, 1, 0};

	for (int i = 1; i <= m; i++)
		ft.update(i, freq[i]);

	cout << "Index | cf" << endl;
	for (int i = 1; i <= m; i++)
		cout << "  " << i << "   | " << ft.query(i) << endl;

	cout << "\nRange sum [5,7] = " << ft.query(5, 7) << endl;

	return 0;
}