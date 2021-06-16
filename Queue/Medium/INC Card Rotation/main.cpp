#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> rotation(int n)
{
    // vector<int> res;
    // for (int i = 0; i < n; i++)
    //     res.push_back(0);

    int res[n] = {0};

    int curr_index = 0;
    for (int i = 1; i <= n; i++)
    {
        curr_index = (curr_index + i) % (n);

        res[curr_index] = i;
        curr_index = (curr_index + 1) % (n);
    }

    for (int i = 0; i < n; i++)
    {
        cout << res[i];
    }

    // return res;
}

int main()
{
    int n = 5;
    vector<int> res = rotation(n);

    for (int i = 1; i < n + 1; i++)
    {
        cout << res[i];
    }
}