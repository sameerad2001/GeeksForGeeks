#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int *A = new int[n], *B = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> B[i];
        }

        delete[] A;
        delete[] B;
    }
}