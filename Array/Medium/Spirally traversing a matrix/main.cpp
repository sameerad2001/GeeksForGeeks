#include <iostream>
#include <vector>

using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
{
    vector<int> list;

    int startRow = 0, endRow = r, startCol = 0, endCol = c;

    while (startRow < endRow && startCol < endCol)
    {
        // Print Elements of the TOP Row
        for (int i = startCol; i < endCol; i++)
        {
            list.push_back(matrix[startRow][i]);
        }
        startRow++;

        // Print Elements of the RIGHT Column
        for (int i = startRow; i < endRow; i++)
        {
            list.push_back(matrix[i][endCol - 1]);
        }
        endCol--;

        // Print Elements in the BOTTOM Row
        if (startRow < endRow)
        {
            for (int i = endCol - 1; i >= startCol; i--)
            {
                list.push_back(matrix[endRow - 1][i]);
            }
            endRow--;
        }

        // Print Elements in the LEFT Column
        if (startCol < endCol)
        {
            for (int i = endRow - 1; i >= startRow; i--)
            {
                list.push_back(matrix[i][startCol]);
            }
            startCol++;
        }
    }

    return list;
}

int main()
{
}