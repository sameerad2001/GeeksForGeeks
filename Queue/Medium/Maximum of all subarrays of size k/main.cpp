#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> max_of_subarrays(int *arr, int n, int k)
{
    deque<int> q;
    vector<int> res;

    for (int i = 0; i < k; i++)
    {
        while (!q.empty() && arr[q.back()] <= arr[i])
            q.pop_back();

        q.push_back(i);
    }

    for (int i = k; i < n; i++)
    {
        res.push_back(q.front());

        if (q.front() <= i - k)
            q.pop_front();

        while (!q.empty() && arr[q.back()] <= arr[i])
            q.pop_back();

        q.push_back(i);
    }

    res.push_back(q.front());
    return res;
}

int main()
{
}