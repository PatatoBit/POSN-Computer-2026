#include <bits/stdc++.h>
using namespace std;

vector<int> createVectorWithoutX(int n, int x)
{
	vector<int> result;
	if (n > 1)
	{
		result.reserve(n - 1);
	}
	for (int i = 1; i <= n; ++i)
	{
		if (i != x)
		{
			result.push_back(i); // Add element to the vector
		}
	}
	return result;
}

void printVector(const vector<int> &v)
{
	for (int x : v)
	{
		cout << x << " ";
	}
	cout << endl;
}

int main()
{
	int n;
	int x;
	cin >> n >> x;

	vector<int> arr(x);
	for (int i = 0; i < x; i++)
		cin >> arr[i];

	auto begin_it = arr.begin();
	auto end_it = arr.end();

	for (int i = 1; i <= n; i++)
	{
		// Starter

		if (find(begin_it, end_it, i) == end_it)
		{
			vector<int> ducklings = createVectorWithoutX(n, i);

			// Print all permutations
			do
			{
				cout << i << " ";
				printVector(ducklings);
			} while (next_permutation(ducklings.begin(), ducklings.end()));
		}
	}

	return 0;
}