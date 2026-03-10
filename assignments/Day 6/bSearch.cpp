#include <bits/stdc++.h>
using namespace std;

int bSearch(int arr[], int left, int right)
{
	if (left > right)
		return -1;

	int mid = (left + right) / 2;
	int k = mid + 1;

	if (arr[mid] == k)
		return mid;
	if (arr[mid] > k)
		return bSearch(arr, left, mid - 1);
	else
		return bSearch(arr, mid + 1, right);
}

int main()
{
	int arr[] = {-4, -3, -1, 0, 1, 2, 6, 8, 9, 13, 14, 19, 20, 24, 26, 35, 48, 49, 80, 90, 92};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = bSearch(arr, 0, n - 1);
	cout << k + 1;

	return 0;
}