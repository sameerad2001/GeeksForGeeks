#include <bits/stdc++.h>
using namespace std;
int M[1001][1001];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        /*Getting the inputs */

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }

        int i = 0, j = 0;
        int dir = 1;

        /*Now we loop till we don't find the boundary */

        while (i < n and j < m and i >= 0 and j >= 0)
        {

            /*Changes the directions if 1 encountered and resets value to 0*/
            if (M[i][j] == 1)
            {
                M[i][j] = 0;
                switch (dir)
                {
                case 1:
                    dir = 2;
                    break;
                case 2:
                    dir = 3;
                    break;
                case 3:
                    dir = 4;
                    break;
                case 4:
                    dir = 1;
                    break;
                }
            }

            /* moves along  based on the direction*/
            switch (dir)
            {
            case 1:
                j++;
                break;
            case 2:
                i++;
                break;
            case 3:
                j--;
                break;
            case 4:
                i--;
                break;
            }
        }

        /* to compensate for the last move */
        switch (dir)
        {
        case 1:
            j--;
            break;
        case 2:
            i--;
            break;
        case 3:
            j++;
            break;
        case 4:
            i++;
            break;
        }

        cout << i << " " << j << endl;
    }
}