#include <bits/stdc++.h>
using namespace std;

int countIntersections(string s1, string s2)
{
	int intersections = 0;
	for (size_t i = 0; i < s1.length(); i++)
	{
		if (s1[i] == s2[i])
		{
			intersections++;
		}
	}

	return intersections;
}

string adrian(int startIndex, int length)
{
	string result = "";

	for (int i = startIndex; i < length + startIndex; i++)
	{
		if (i % 3 == 0)
			result += "A";
		else if (i % 3 == 1)
			result += "B";
		else if (i % 3 == 2)
			result += "C";
	}

	return result;
}

string bruno(int startIndex, int length)
{
	string result = "";

	for (int i = startIndex; i < length + startIndex; i++)
	{
		if (i % 4 == 0)
			result += "B";
		else if (i % 4 == 1)
			result += "A";
		else if (i % 4 == 2)
			result += "B";
		else if (i % 4 == 3)
			result += "C";
	}

	return result;
}

string goran(int startIndex, int length)
{
	string result = "";

	for (int i = startIndex; i < length + startIndex; i++)
	{
		if (i % 6 == 0 || i % 6 == 1)
			result += "C";
		else if (i % 6 == 2 || i % 6 == 3)
			result += "A";
		else if (i % 6 == 4 || i % 6 == 5)
			result += "B";
	}

	return result;
}

int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;

	// Adrian
	int adrianMax = countIntersections(s, adrian(0, n));
	string bestAdrian = adrian(0, n);

	// cout << adrianMax << endl;
	// cout << bestAdrian << endl;

	// Bruno
	int brunoMax = countIntersections(s, bruno(0, n));
	string bestBruno = bruno(0, n);

	// cout << brunoMax << endl;
	// cout << bestBruno << endl;

	// Goran
	int goranMax = countIntersections(s, goran(0, n));
	string bestGoran = goran(0, n);

	// cout << goranMax << endl;
	// cout << bestGoran << endl;

	// Print out the best results
	int bestAmongThree = max({adrianMax, brunoMax, goranMax});
	cout << bestAmongThree << endl;

	if (adrianMax == bestAmongThree)
		cout << "Adrian" << endl;
	if (brunoMax == bestAmongThree)
		cout << "Bruno" << endl;
	if (goranMax == bestAmongThree)
		cout << "Goran";

	return 0;
}