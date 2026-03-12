#include <bits/stdc++.h>
using namespace std;

// int findPlatform(vector<int> &arr, vector<int> &dep)
// {
// 	int n = arr.size();
// 	int ans = 0;

// 	// Run a nested for-loop to find the overlap
// 	for (int i = 0; i < n; i++)
// 	{
// 		// Initially one platform is needed
// 		int cnt = 1;
// 		for (int j = 0; j < n; j++)
// 		{
// 			if (i != j)
// 				// Increment cnt if trains have overlapping
// 				// time.
// 				if (arr[i] >= arr[j] && dep[j] >= arr[i])
// 					cnt++;
// 		}
// 		// Update the result
// 		ans = max(cnt, ans);
// 	}
// 	return ans;
// }

int findPlatform(vector<int> &arr, vector<int> &dep)
{
	int n = arr.size();
	int ans = 0;
	// Find the max Departure time
	int maxDep = dep[0];
	for (int i = 1; i < n; i++)
	{
		maxDep = max(maxDep, dep[i]);
	}
	// Create a vector to store the count of trains at each time
	vector<int> v(maxDep + 2, 0);
	// Increment the count at the arrival time and decrement at	the departure time
	for (int i = 0; i < n; i++)
	{
		v[arr[i]]++;
		v[dep[i] + 1]--;
	}
	int count = 0;
	// Iterate over the vector and keep track of the maximum
	// sum seen so far
	for (int i = 0; i <= maxDep + 1; i++)
	{
		count += v[i];
		ans = max(ans, count);
	}
	return ans;
}

int main()
{
	vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
	vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
	cout << findPlatform(arr, dep);

	return 0;
}