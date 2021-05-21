#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//  Wrong next greater element not any great elem to the right
vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    stack<long long> st;

    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty() || arr[i] > st.top())
        {
            st.push(arr[i]);
        }
    }

    vector<long long> res;
    for (int i = 0; i < n; i++)
    {
        if (!st.empty() && st.top() > arr[i])
        {
            res.push_back(st.top());
        }
        else // if (st.top() == arr[i])
        {
            res.push_back(-1);
            st.pop();
        }
    }

    return res;
}

int main()
{
}