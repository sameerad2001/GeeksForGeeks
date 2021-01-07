// UNORDERED SETS

#include <bits/stdc++.h>
using namespace std;

// Function for finding
// elements which are there
// in a[] but not in b[].
void findMissing(long a[], long b[], int n, int m)
{
    // Store all elements of
    // second array in a hash table
    unordered_set<int> s;
    for (int i = 0; i < m; i++)
        s.insert(b[i]);

    // Print all elements of
    // first array that are not
    // present in hash table
    for (int i = 0; i < n; i++)
        if (s.find(a[i]) == s.end())
            cout << a[i] << " ";
}

// Driver code
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        long *A = new long[n];
        long *B = new long[m];

        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> B[i];
        }

        findMissing(A, B, n, m);

        cout << endl;
        delete[] A, B;
    }
    return 0;
}