#include <iostream>
#include <vector>

using namespace std;

vector<int> findSubarray(int a[], int n)
{
    // code here
    long loc1 = -1, loc2 = -1;
    long left = -1, right = 0, oriSum = 0, tempSum = 0;

    vector<int> ans;

    while (right < n && left <= right)
    {
        tempSum = 0;
        while (right < n && a[right] >= 0)
        {
            tempSum += a[right];
            ++right;
        }

        if (tempSum > oriSum)
        {
            oriSum = tempSum;
            loc1 = left;
            loc2 = right - 1;
        }
        else if ((tempSum == oriSum) && ((right - left) > (loc2 - loc1)))
        {
            loc1 = left;
            loc2 = right - 1;
        }

        while (right < n && a[right] < 0)
            ++right;

        left = right - 1;
    }

    for (int i = loc1 + 1; i <= loc2; ++i)
    {
        ans.push_back(a[i]);
    }

    if (ans.size() == 0)
        ans.push_back(-1);

    return ans;
}