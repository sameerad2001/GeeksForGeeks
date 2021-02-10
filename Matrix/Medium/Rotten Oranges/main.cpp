#include <iostream>
#include <vector>

using namespace std;

//Efficient : BFS

// Naive Approach
int orangesRotting(vector<vector<int>> &grid)
{
    int time = -1;
    bool flag = true;

    while (flag)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    //     if (i > 0 && grid[i - 1][j] == 1)
                    //         grid[i - 1][j] = 2;

                    //     if (j > 0 && grid[i][j - 1] == 1)
                    //         grid[i][j - 1] = 2;

                    //     if (i > 0 && j > 0 && grid[i - 1][j - 1] == 1)
                    //         grid[i - 1][j - 1] = 2;
                }
            }
        }
    }
}

int main()
{
}