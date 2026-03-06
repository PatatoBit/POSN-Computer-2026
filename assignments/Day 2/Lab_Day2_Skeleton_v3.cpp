#include <bits/stdc++.h>
using namespace std;

/*
Lab Day 2: Stack & Queue Pattern (v3 - Interactive)

This program lets you choose which problem to run.
Just follow the on-screen instructions.
*/

static void printVec(const vector<int> &v)
{
    if (v.empty())
    {
        cout << "(empty)\n";
        return;
    }
    for (int i = 0; i < (int)v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << "\n";
}

// ------------------ TODO ------------------

// Level 1
vector<int> nextGreater(const vector<int> &a)
{
    // TODO: implement using monotonic stack
    int n = a.size();
    stack<int> s;
    vector<int> ans(n);

    for (int i = a.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= a[i])
        {
            s.pop();
        }

        if (s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();

        s.push(a[i]);
    }

    return ans;
}

// Level 2
vector<int> slidingWindowMax(const vector<int> &a, int k)
{
    // TODO: implement using monotonic deque
    int n = a.size();
    deque<int> dq;
    vector<int> output;

    int it = 0;
    for (auto el : a)
    {
        while (!dq.empty() && (dq.size() >= k || dq.front() < el))
        {
            dq.pop_front();
        }

        dq.push_back(el);

        if (it >= k - 1)
        {
            output.push_back(dq.front());
        }

        it++;
    }

    return output;
}

// ------------------ MAIN ------------------

int main()
{
    cout << "==============================\n";
    cout << " Lab Day 2 - Stack & Queue\n";
    cout << "==============================\n\n";

    cout << "Choose problem:\n";
    cout << "1) Next Greater Element\n";
    cout << "2) Sliding Window Maximum\n";
    cout << "Enter choice (1-2): ";

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        cout << "\nEnter n: ";
        int n;
        cin >> n;
        vector<int> a(n);
        cout << "Enter " << n << " integers:\n";
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << "Output:\n";
        printVec(nextGreater(a));
    }
    else if (choice == 2)
    {
        cout << "\nEnter n and k: ";
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        cout << "Enter " << n << " integers:\n";
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << "Output:\n";
        printVec(slidingWindowMax(a, k));
    }
    else
    {
        cout << "Invalid choice.\n";
    }

    cout << "\nProgram finished.\n";
    return 0;
}
