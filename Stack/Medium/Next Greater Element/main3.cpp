#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    stack<int> no_next_great;
    vector<long long> res;

    for (int i = 0; i < n; i++)
    {
        res.push_back(-1);
    }

    for (int i = 0; i < n; i++)
    {
        while (!no_next_great.empty() && arr[i] > arr[no_next_great.top()])
        {
            int index = no_next_great.top();
            res[index] = arr[i];
            no_next_great.pop();
        }

        no_next_great.push(i);
    }

    // while (!no_next_great.empty())
    // {
    //     int index = no_next_great.top();
    //     res[index] = -1;
    //     no_next_great.pop();
    // }

    // res[n - 1] = -1;

    return res;
}

int main()
{
    vector<long long> arr = {1, 3, 2, 4};
    vector<long long> res = nextLargerElement(arr, 4);

    for (int i = 0; i < 4; i++)
    {
        cout << res[i] << " ";
    }
}