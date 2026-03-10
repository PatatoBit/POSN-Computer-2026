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
	{
		cout << "Vector size mismatch" << endl;
		return -1;
	}

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

	for (int i = 0; i < n; i++)
	{
		cin >> prices[i];
	}

	cout << endl;

	int closestMatch = 0;
	vector<bool> minActivation;

	for (int i = 0; i < pow(2, n); i++)
	{
		string binary = "";
		int temp = i;

		for (int j = 0; j < n; j++)
		{
			binary = to_string(temp % 2) + binary;
			temp /= 2;
		}

		vector<bool> activationVector = stringToActivation(binary);
		int matchedValue = activationToValue(prices, activationVector);

		if (matchedValue >= closestMatch && matchedValue <= budget)
		{
			closestMatch = matchedValue;
			minActivation = activationVector;
		}

		if (matchedValue == budget)
			break;
	}

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (minActivation[i])
		{
			cout << prices[i] << " ";
			count++;
		}
	}

	cout << endl;
	cout << closestMatch << " " << count;

	return 0;
}