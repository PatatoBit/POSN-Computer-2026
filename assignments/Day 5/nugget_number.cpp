#include <bits/stdc++.h>
using namespace std;

bool isNugget(int n)
{
	// 6a + 9b + 20c = n

	for (int a = 0; a <= (n / 6) + 1; a++)
	{
		for (int b = 0; b <= (n / 9) + 1; b++)
		{
			for (int c = 0; c <= (n / 20) + 1; c++)
			{
				if (6 * a + 9 * b + 20 * c == n)
					return true;
			}
		}
	}

	return false;
}

int main()
{
	int arr[6];
	for (int i = 0; i < 6; i++)
	{
		cin >> arr[i];
	}

	for (int num : arr)
	{
		if (isNugget(num))
			cout << num << " ";
	}

	return 0;
}