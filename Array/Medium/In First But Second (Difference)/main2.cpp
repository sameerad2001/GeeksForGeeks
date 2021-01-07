#include <iostream>
#include <algorithm>

using namespace std;

long *difference(long A[], long B[], int n, int m)
{
    sort(A, A + n);
    sort(B, B + m);

    long *C = new long[n + m];

    for (int i = 0; i < n + m; i++)
    {
        C[i] = -1;
    }

    int k, i, j;
    i = j = k = 0;

    while (i < n && j < m)
    {
        if (A[i] > B[j])
        {
            j++;
        }
        else if (A[i] == B[j])
        {
            i++;
            j++;
        }
        else
        {
            C[k++] = A[i++];
        }
    }

    while (i < n)
    {
        C[k++] = A[i++];
    }

    return C;
}

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
        long *C = new long[n + m];

        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> B[i];
        }

        C = difference(A, B, n, m);

        for (int i = 0; C[i] != -1; i++)
        {
            cout << C[i] << " ";
        }

        cout << endl;
        delete[] A, B, C;
    }
}