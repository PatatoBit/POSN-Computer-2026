#include <bits/stdc++.h>
using namespace std;

struct SubArray
{
	int left;
	int right;
	int sum;
};

SubArray findMaxSubarray(const vector<int> &v)
{
	int maxSubarray = v[0];
	int left = 0, right = 0;
	int currentLeft = 0, currentSum = 0;

	int n = v.size();

	for (int i = 0; i < n; i++)
	{
		if (currentSum <= 0)
		{
			currentLeft = i;
			currentSum = v[i];
		}
		else
		{
			currentSum += v[i];
		}

		if (currentSum > maxSubarray)
		{
			maxSubarray = currentSum;
			left = currentLeft;
			right = i;
		}
	}

	// cout << "Left: " << left << endl;
	// cout << "Right: " << right << endl;
	// cout << "Max: " << maxSubarray << endl;
	return {left, right, maxSubarray};
}

vector<int> dailyChanges(const vector<int> &v)
{
	int n = v.size();
	vector<int> output(n);

	for (int i = 1; i < n; i++)
		output[i] = v[i] - v[i - 1];

	return output;
}

void printVector(const vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];

		if (i != v.size() - 1)
			cout << ", ";
	}
}

int main()
{
	vector<int> prices = {100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};
	SubArray result = findMaxSubarray(dailyChanges(prices));

	cout << "Left: " << result.left << endl;
	cout << "Right: " << result.right << endl;
	// cout << "Max: " << maxSubarray << endl;

	for (int i = result.left; i <= result.right; i++)
	{
		cout << prices[i];

		if (i != result.right)
			cout << ", ";
	}

	return 0;
}