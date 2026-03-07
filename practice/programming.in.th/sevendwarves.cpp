// https://programming.in.th/tasks/0013

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int sum = 0, max = 100;
	int arr[9];

	for (int i = 0; i < 9; i++)
	{
		int x;
		cin >> x;

		arr[i] = x;
		sum += x;
	}

	// cout << "Sum: " << sum << endl;

	int excess = sum - max;
	int removeI = -1, removeJ = -1;

	// cout << "Excess: " << excess << endl;

	for (int i = 8; i >= 0; i--)
	{
		// cout << arr[i] << endl;

		for (int j = 0; j < 8; j++)
		{
			// cout << "I: " << arr[i] << " J: " << arr[j] << endl;

			if (arr[i] + arr[j] == excess)
			{
				removeI = i;
				removeJ = j;
				break;
			}
		}

		if (removeI != -1)
			break;

		// cout << endl;
	}

	for (int i = 0; i < 9; i++)
	{
		if (i != removeI && i != removeJ)
		{
			cout << arr[i] << '\n';
		}
	}

	return 0;
}