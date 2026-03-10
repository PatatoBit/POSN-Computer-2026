#include <bits/stdc++.h>
using namespace std;

int findDuplicate(int arr[], int left, int right)
{
	if (left > right)
		return -1;

	int mid = (left + right) / 2;

	if (arr[mid] == arr[mid - 1])
		return arr[mid];

	if (arr[mid] > mid)
		return findDuplicate(arr, mid + 1, right);
	else
		return findDuplicate(arr, left, mid - 1);

	return 0;
}

int main()
{
	int arr[] = {1, 10, 19, 15, 14, 9, 13, 12, 11, 8, 7, 3, 4, 6, 16, 17, 20, 2, 5, 18, 16};
	int n = sizeof(arr) / sizeof(arr[0]);
	sort(arr, arr + n);

	cout << findDuplicate(arr, 0, n);

	return 0;
}