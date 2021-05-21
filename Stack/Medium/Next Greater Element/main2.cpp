#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//  Naive Approach : O(n^2)
vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    vector<long long> res;

    for (int i = 0; i < n - 1; i++)
    {
        bool assigned = false;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                assigned = true;
                // res[i] = arr[j];
                res.push_back(arr[j]);
                break;
            }
        }

        if (!assigned)
            res.push_back(-1);
    }
    res.push_back(-1);

    return res;
}

int main()
{
    vector<long long> arr = {1, 3, 2, 4};
    vector<long long> res = nextLargerElement(arr, 4);

    for (int i = 0; i < 4; i++)
    {
        cout << res[i];
    }
}