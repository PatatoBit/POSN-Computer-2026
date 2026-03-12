#include <bits/stdc++.h>
using namespace std;

void printVector(const vector<pair<int, int>> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << "(" << v[i].first << ", " << v[i].second << ")";

		if (i != v.size() - 1)
			cout << ", ";
	}

	cout << endl;
}

vector<pair<int, int>> sortPair(const vector<pair<int, int>> &v)
{
	vector<pair<int, int>> output = v;
	sort(output.begin(), output.end(), [](const pair<int, int> &left, const pair<int, int> right)
			 { return left.second < right.second; });

	return output;
}

int maxActivity(const vector<pair<int, int>> &v)
{
	int n = v.size();
	int count = 1;
	int minStart = v[0].second;

	for (int i = 1; i < n; i++)
	{
		if (v[i].first >= minStart)
		{
			count++;
			minStart = v[i].second;
		}
	}

	return count;
}

int main()
{
	// Each pair is (start_time, finish_time).
	vector<pair<int, int>> activities1 = {
			pair<int, int>{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 9}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 14}, {12, 16}};

	vector<pair<int, int>> activities2 = {
			pair<int, int>{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};

	activities1 = sortPair(activities1);
	activities2 = sortPair(activities2);

	cout << maxActivity(activities1) << endl;
	cout << maxActivity(activities2);

	return 0;
}