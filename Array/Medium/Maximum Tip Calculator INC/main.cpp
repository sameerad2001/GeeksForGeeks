
//Requires Vectors of pairs
//hint Absolute difference

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

// Desending order
int compare(const void *x, const void *y)
{
    return (*(int *)y) - (*(int *)x);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;

        int *a = new int[n];
        int *b = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int *difference = new int[n];

        for (int i = 0; i, n; i++)
        {
            difference[i] = abs(a[i] - b[i]);
        }

        qsort(difference, n, sizeof(int), compare);

        delete difference;
        delete a;
        free(b);
    }
}