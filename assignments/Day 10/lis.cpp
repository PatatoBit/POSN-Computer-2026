#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &v, int left, int right)
{
	int x = right;
	int l = left;
	int r = (int)v.size() - 1;
	int ans = (int)v.size();

	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (v[mid] >= x)
		{
			ans = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}

	return ans;
}

int LIS(vector<int> &a)
{
	if (a.empty())
		return 0;

	vector<int> L;
	L.push_back(a[0]);

	for (int i = 1; i < (int)a.size(); i++)
	{
		auto it = lower_bound(L.begin(), L.end(), a[i]);

		if (it == L.end())
			L.push_back(a[i]);
		else
			*it = a[i];
	}

	return (int)L.size();
}

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << LIS(arr);

	return 0;
}