#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> binTreeSortedLevels(int arr[], int n)
{
    queue<int> q_index;
    // Push Index of root
    q_index.push(0);

    vector<vector<int>> res;

    vector<int> root;
    root.push_back(arr[0]);
    res.push_back(root);

    bool complete = false;
    while (!complete)
    {
        queue<int> q_temp;
        while (!q_index.empty())
        {
            if (q_index.front() * 2 + 1 >= n || q_index.front() * 2 + 2 >= n)
            {
                complete = true;
            }

            // Left Child
            if (q_index.front() * 2 + 1 >= n)
                q_temp.push(q_index.front() * 2 + 1);
            // Right Child
            if (q_index.front() * 2 + 2 >= n)
                q_temp.push(q_index.front() * 2 + 2);

            q_index.pop();
        }

        vector<int> vec_temp;
        while (!q_temp.empty())
        {
            vec_temp.push_back(arr[q_temp.front()]);
            q_index.push(q_temp.front());
            q_temp.pop();
        }

        sort(vec_temp.begin(), vec_temp.end());
        res.push_back(vec_temp);
    }

    return res;
}

int main()
{
}