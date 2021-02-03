#include <iostream>
#include <vector>

using namespace std;

vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
{
    // code here
    // code here
    vector<int> qr;

    for (int i = 0; i < q; ++i)
    {
        vector<int> query = queries[i];
        int hop = query[0];
        int src_i = query[1];
        int src_j = query[2];
        int sum = 0;
        if (hop == 1)
        {
            for (int k = -hop; k <= hop; ++k)
            {
                for (int t = -hop; t <= hop; ++t)
                {
                    int dst_i = src_i + k;
                    int dst_j = src_j + t;
                    if (dst_i < 0 || dst_j < 0 || dst_i >= n || dst_j >= m || (k == 0 && t == 0))
                        continue;
                    sum += mat[dst_i][dst_j];
                }
            }
        }

        else
        {

            for (int k = -hop; k <= hop; k += hop)
            {
                if (k == 0)
                    continue;

                for (int t = -hop; t <= hop; ++t)
                {

                    int dst_i = src_i + k;
                    int dst_j = src_j + t;

                    if (dst_i < 0 || dst_j < 0 || dst_i >= n || dst_j >= m || (k == 0 && t == 0))
                        continue;

                    sum += mat[dst_i][dst_j];
                }
            }

            for (int t = -hop; t <= hop; t += hop)
            {
                for (int k = -1; k <= 1; ++k)
                {
                    if (t == 0)
                        continue;
                    int dst_i = src_i + k;
                    int dst_j = src_j + t;
                    if (dst_i < 0 || dst_j < 0 || dst_i >= n || dst_j >= m || (k == 0 && t == 0))
                        continue;
                    sum += mat[dst_i][dst_j];
                }
            }
        }

        qr.push_back(sum);
    }
    return qr;
}