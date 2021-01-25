#include <iostream>
#include <vector>

using namespace std;

/* 
   Directions
   0 : RIGHT >
   1 : DOWN V
   2 : LEFT <
   3 : UP ^  
*/

// int resx = 0, resy = 0;

int mat[1001][1001];

void exitPoint(int n, int m)
{
    int dir = 0;
    int i = 0, j = 0;

    while (true)
    {
        // dir = (dir + mat[i][j]) % 4;

        if (mat[i][j] == 1)
        {
            mat[i][j] = 0;
        }

        switch (dir)
        {
        case 0: // > RIGHT
            j++;
            break;
        case 1: // V DOWN
            i++;
            break;
        case 2: // < LEFT
            j--;
            break;
        case 3: // ^ UP
            i--;
            break;
        }

        dir = (dir + mat[i][j]) % 4;

        if (j < 0)
        {
            j++;
            break;
        }
        else if (j >= m)
        {
            j--;
            break;
        }
        else if (i < 0)
        {
            i++;
            break;
        }
        else if (i >= n)
        {
            i--;
            break;
        }
    }

    cout << i << " " << j << "\n";
    // return i + j * (n > m ? n : m);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        // vector<vector<int>> mat;

        for (int i = 0; i < n; i++)
        {
            vector<int> temp;

            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
                // int data;
                // cin >> data;
                // temp.push_back(data);
            }

            // mat.push_back(temp);
        }

        // int res = exitPoint(mat, n, m);
        // cout << res % (n > m ? n : m) << " " << res / (n > m ? n : m) << "\n";

        exitPoint(n, m);

        // cout << resx << resy;
    }
}