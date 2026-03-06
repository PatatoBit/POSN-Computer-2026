
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

long long power(int a, int n)
{
    // TODO
    if (n == 1)
        return a;
    else
        return a * power(a, n - 1);
}

int sumArray(int arr[], int n)
{
    // TODO
    if (n <= 0)
        return 0;
    if (n == 1)
        return arr[0];
    else
        return arr[n - 1] + sumArray(arr, n - 1);
}

void mirror(int n)
{
    // TODO
    if (n <= 0)
        return;
    if (n == 1)
    {
        cout << "1 1";
        return;
    }

    cout << n << " ";
    mirror(n - 1);
    cout << " " << n;
}

Node *reverse(Node *head)
{
    // TODO
}

int main()
{

    cout << "Recursion Lab Test Menu\n";
    cout << "1. Power Function\n";
    cout << "2. Sum Array\n";
    cout << "3. Mirror Print\n";

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        int a, n;
        cin >> a >> n;
        cout << power(a, n);
    }

    if (choice == 2)
    {
        int n;
        cin >> n;
        int arr[100];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << sumArray(arr, n);
    }

    if (choice == 3)
    {
        int n;
        cin >> n;
        mirror(n);
    }

    return 0;
}
