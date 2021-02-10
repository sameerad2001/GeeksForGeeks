#include <iostream>
#include <vector>
#include <string>

using namespace std;

int x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool ifPattern(int row, int col, vector<vector<char>> grid, string word)
{

    if (grid[row][col] != word[0])
        return false;

    if (grid[row][col] == word[0] && word.length() == 1)
        return true;

    int n = grid.size();
    int m = grid[0].size();
    int len = word.length();

    for (int dir = 0; dir < 8; dir++)
    {
        int k = 1,
            check_row = row + x[dir],
            check_col = col + y[dir];

        for (; k < len; k++)
        {
            if (check_row >= n || check_row < 0 || check_col >= m || check_col < 0)
                break;

            if (grid[check_row][check_col] != word[k])
                break;

            check_row += x[dir],
                check_col += y[dir];
        }

        if (k >= len)
            return true;
    }

    return false;
}

void search(int n, int m, vector<vector<char>> grid, string word)
{
    bool notFound = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ifPattern(i, j, grid, word))
            {
                cout << i << " "
                     << j << ", ";
                notFound = false;
            }
        }
    }

    if (notFound)
    {
        cout << "-1";
    }

    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid;

        for (int i = 0; i < n; i++)
        {
            vector<char> temp;
            for (int j = 0; j < m; j++)
            {
                char value;
                cin >> value;
                temp.push_back(value);
            }

            grid.push_back(temp);
        }

        string word;
        cin >> word;

        search(n, m, grid, word);
    }
}