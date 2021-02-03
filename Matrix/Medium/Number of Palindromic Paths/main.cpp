#include <iostream>

using namespace std;

#define n 10
#define m 10

int r, c;

int path(char arr[n][m], start, end)
{
    if (arr[0][0])
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> r >> c;
        char arr[r][c];

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> arr[i][j];
            }
        }

        cout << path(arr);
    }
}