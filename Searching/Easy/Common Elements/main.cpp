#include <iostream>
#include <vector>

using namespace std;

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    int i, j, k;
    i = j = k = 0;

    vector<int> res;

    while (i < n1 && j < n2 && k < n3)
    {
        // Duplicate have to be considered only ONCE
        while (i < n1 and A[i - 1] == A[i])
            i++;

        while (j < n2 and B[j - 1] == B[j])
            j++;

        while (k < n3 and C[k - 1] == C[k])
            k++;

        if (i < n1 && j < n2 && k < n3)
        {
            if (A[i] == B[j] && B[j] == C[k])
            {
                res.push_back(A[i]);
                i++;
                j++;
                k++;
            }
            else if (A[i] < B[j])
            {
                i++;
            }
            else if (B[j] < C[k])
            {
                j++;
            }
            else
            {
                k++;
            }
        }
    }

    return res;
}

int main() {}