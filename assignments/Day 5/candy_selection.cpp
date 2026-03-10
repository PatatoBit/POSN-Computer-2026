#include <bits/stdc++.h>
using namespace std;

vector<bool> stringToActivation(string s)
{
	vector<bool> output;
	for (char c : s)
		output.push_back(c - '0');

	return output;
}

int activationToValue(const vector<int> &prices, const vector<bool> &activation)
{
	if (prices.size() != activation.size())
		cout << "Vector size mismatch" << endl;

	int sum = 0;
	for (int i = 0; i < prices.size(); i++)
	{
		sum += prices[i] * activation[i];
	}

	return sum;
}

void printVector(const vector<bool> &v)
{
	for (bool b : v)
		cout << b << " ";
	cout << endl;
}

int main()
{
	int budget, n;
	cin >> budget >> n;

	vector<int> prices(n);
	vector<bool>(n, 0);

	for (int i = 0; i < n; i++)
		cin >> prices[i];

	for (int i = 0; i < pow(2, n); i++)
	{
		string binary = "";
		int temp = i;

		for (int j = 0; j < n; j++)
		{
			binary = to_string(temp % 2) + binary;
			temp /= 2;
		}

		// printVector(stringToActivation(binary));

		// Array matching
		// ax + by + cz + ...
		for (int j = 0; j < n; j++)
		{
			int matchedValue = activationToValue(prices, stringToActivation(binary));
			if (matchedValue == budget)
				cout << "Found match!" << endl;

			cout << matchedValue << endl;
			printVector(stringToActivation(binary));
		}
	}

	return 0;
}