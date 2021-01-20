#include <iostream>
#include <vector>

using namespace std;

#define MAX 10000

int findK(int A[MAX][MAX], int n, int m, int k)
{
    int startRow = 0, endRow = n;
    int startCol = 0, endCol = m;

    int count = 0;

    while (startRow < endRow && startCol < endCol)
    {
        for (int i = startCol; i < endCol; i++)
        {
            count++;
            if (count == k)
            {
                return A[startRow][i];
            }
        }
        startRow++;

        for (int i = startRow; i < endRow; i++)
        {
            count++;
            if (count == k)
            {
                return A[i][endCol - 1];
            }
        }
        endCol--;

        for (int i = endCol - 1; i >= startCol; i--)
        {
            count++;
            if (count == k)
            {
                return A[endRow - 1][i];
            }
        }
        endRow--;

        for (int i = endRow - 1; i >= startRow; i--)
        {
            count++;
            if (count == k)
            {
                return A[i][startCol];
            }
        }
        startCol++;
    }
}

int main() {}