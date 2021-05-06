#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> maxOfMin(int arr[], int n)
{
    int left[n], right[n];
    stack<int> st;

    // Previous Minimum
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        if (!st.empty())
            left[i] = st.top();
        else
            left[i] = -1;

        st.push(i);
    }

    while (!st.empty())
        st.pop();

    // Next Minimum
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        if (!st.empty())
            right[i] = st.top();

        else
            right[i] = n;

        st.push(i);
    }

    vector<int> res;
    for (int i = 0; i <= n; i++)
        res.push_back(0);

    for (int i = 0; i < n; i++)
    {
        int len = right[i] - left[i] - 1;

        res[len] = max(res[len], arr[i]);
    }

    for (int i = n - 1; i >= 1; i--)
    {
        res[i] = res[i] > res[i + 1] ? res[i] : res[i + 1];
    }

    res.erase(res.begin()); // remove 0th index as there are no max elements in window of size 0

    return res;
}

int main()
{
}