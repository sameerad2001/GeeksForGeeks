#include <iostream>
#include <stdio.h>

#define maximum(a, b) a > b ? a : b

using namespace std;

int **arr;

/*void interchange(int n, int m)
{
    int temp;

    for (int i = 0; i < n; i++)
    {
        temp = arr[i][m - 1];
        arr[i][m - 1] = arr[i][0];
        arr[i][0] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}*/

int main()
{
    int n, m;
    cin >> n >> m;

    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];

        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    //interchange(n, m);

    int temp;

    for (int i = 0; i < n; i++)
    {
        temp = arr[i][m - 1];
        arr[i][m - 1] = arr[i][0];
        arr[i][0] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    free(arr);
}
