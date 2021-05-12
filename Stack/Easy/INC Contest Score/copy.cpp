#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void generatensr(vector<int> nums, vector<int> &nsr)
{
    stack<int> st;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[i] <= nums[st.top()])
        {
            st.pop();
        }
        if (st.empty())
            nsr.push_back(-1);
        else
            nsr.push_back(st.top() + 1);
        st.push(i);
    }
    // reverse(nsr.begin(), nsr.end());
}