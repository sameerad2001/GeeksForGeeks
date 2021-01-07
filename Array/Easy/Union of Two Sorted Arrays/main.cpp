#include <iostream>
#include <vector>

using namespace std;

vector<int> findUnion(int A[], int B[], int n, int m)
{
    int i = 0, j = 0;
    vector<int> C;

    while (i < n && j < m)
    {

        if (A[i] < B[j])
        {
            C.push_back(A[i]);

            if (A[i] == A[i + 1])
            {
                while (A[i] == A[i + 1])
                {
                    i++;
                }
                i++;
            }

            else
            {
                i++;
            }
        }
        else if (A[i] == B[j])
        {
            C.push_back(A[i]);
            if (A[i] == A[i + 1])
            {

                while (A[i] == A[i + 1])
                {
                    i++;
                }
                i++;
            }
            else
            {
                i++;
            }

            if (B[j] == B[j + 1])
            {
                while (B[j] == B[j + 1])
                {
                    j++;
                }
                j++;
            }
            else
            {
                j++;
            }
        }
        else
        {
            C.push_back(B[j]);
            //j++;

            if (B[j] == B[j + 1])
            {
                while (B[j] == B[j + 1])
                {
                    j++;
                }
                j++;
            }
            else
            {
                j++;
            }
        }
    }

    while (i < n)
    {
        C.push_back(A[i]);

        if (A[i] == A[i + 1])
        {
            while (A[i] == A[i + 1])
            {
                i++;
            }
            i++;
        }
        else
        {
            i++;
        }
    }

    while (j < m)
    {
        C.push_back(B[j]);
        if (B[j] == B[j + 1])
        {
            while (B[j] == B[j + 1])
            {
                j++;
            }
            j++;
        }

        else
        {
            j++;
        }
    }

    return C;
}

int main()
{
    int n, m;
    int *A = new int[n];
    int *B = new int[m];

    delete[] A, B;
}