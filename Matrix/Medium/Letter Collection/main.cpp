#include <iostream>
#include <vector>

using namespace std;

// queries =  {{1 0 1},
//             {2 0 1}}

vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
{
    vector<int> res;

    for (int i = 0; i < q; i++)
    {
        vector<int> query = queries[i];

        int option = query[0];
        int x = query[1];
        int y = query[2];

        int sum = 0;

        if (option == 1)
        {
            for (int row = -option; row <= option; row++)
            {
                for (int colm = -option; colm <= option; colm++)
                {
                    int index_i = x + row;
                    int index_j = y + colm;

                    if (index_i < 0 || index_j < 0 || index_i >= n || index_j >= m || (index_i == x && index_j == y))
                    {
                        continue;
                    }
                    sum += mat[index_i][index_j];
                }
            }
        }

        else
        {
            for (int row = -option; row <= option; row += option)
            {
                if (row == 0)
                    continue;

                for (int colm = -option; colm <= option; colm++)
                {
                    int index_i = x + row;
                    int index_j = y + colm;

                    if (index_i < 0 || index_j < 0 || index_i >= n || index_j >= m || (index_i == x && index_j == y))
                    {
                        continue;
                    }
                    sum += mat[index_i][index_j];
                }
            }

            for (int colm = -option; colm <= option; colm += option)
            {

                if (colm == 0)
                {
                    continue;
                }

                for (int row = -1; row <= 1; row++)
                {
                    int index_i = x + row;
                    int index_j = y + colm;

                    if (index_i < 0 || index_j < 0 || index_i >= n || index_j >= m || (index_i == x && index_j == y))
                    {
                        continue;
                    }

                    sum += mat[index_i][index_j];
                }
            }
        }

        res.push_back(sum);
    }

    return res;
}

int main()
{
}