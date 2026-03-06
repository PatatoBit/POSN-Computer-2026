#include <bits/stdc++.h>
using namespace std;

int n = 0;

vector<int> nextGreater(vector<int> &a, n)
{
	vector<int> ans(n);
	stack<int> st;
	for (int i = n - 1; i >= 0; i--)
	{
		while (!st.empty() && st.top() <= a[i])
		{
			st.pop();
		}
		if (st.empty())
			ans[i] = -1;
		else
			ans[i] = st.top();
		st.push(a[i]);
	}
	return ans;
}
int main()
{

	return 0;
}