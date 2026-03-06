
#include <iostream>
using namespace std;

// TODO: Generate all binary strings of length n using recursion
void generateBinary(int n, string current)
{

    // base case?
    if (n == 1)
        cout << "1";
    else
        cout << "0";

    // print string?

    // recursive calls
    // add '0'
    // add '1'
}

int main()
{

    int n;
    cout << "Enter n: ";
    cin >> n;

    generateBinary(n, "");

    return 0;
}
