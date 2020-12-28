#include <iostream>
#include <stdio.h>

using namespace std;

//OR USE QUICK SORT; cant be used in gog
void matchPairs(char nuts[], char bolts[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nuts[i] > nuts[j])
            {
                temp = nuts[i];
                nuts[i] = nuts[j];
                nuts[j] = temp;
            }

            if (bolts[i] > bolts[j])
            {
                temp = bolts[i];
                bolts[i] = bolts[j];
                bolts[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int *nuts = new int[n];
    int *bolts = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> nuts[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> bolts[i];
    }

    free(nuts);
    free(bolts);
}