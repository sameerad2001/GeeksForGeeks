#include <iostream>
#include <vector>

using namespace std;

vector<int> findSubarray(int arr[], int n)
{
    vector<int> res;

    int left = -1, right = 0;
    int loc1 = -1, loc2 = -1;

    long temp, maxSum = 0;

    while (right < n && left <= right)
    {
        temp = 0;

        while (right < n && arr[right] >= 0) //**** < '=' 0  Otherwise INFINITE LOOP
        {
            temp += arr[right++];
        }

        if (temp > maxSum)
        {
            maxSum = temp;
            loc1 = left;
            loc2 = right - 1; //current right is where required conditions failed
        }

        else if ((temp == maxSum) && (right - left) > (loc2 - loc1))
        {
            // More Elementsin the SubArray
            loc1 = left;
            loc2 = right - 1;
        }

        while (right < n && arr[right] < 0)
            right++;

        left = right - 1;
    }

    for (int i = loc1 + 1; i <= loc2; i++)
    {
        res.push_back(arr[i]);
    }

    if (res.size() == 0)
        res.push_back(-1);

    return res;
}

int main()
{
    int n;
}