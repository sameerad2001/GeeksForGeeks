#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
1) Create a new empty stack S

2) For every element 'arr[i]' in the input sequence 'arr[]',
   where 'i' goes from 0 to n-1.
    a) while S is nonempty and the top element of 
       S is greater than or equal to 'arr[i]':
           pop S
    
    b)    
        b 1) if S is empty:
           'arr[i]' has no preceding smaller value
        b 2) else:
           the nearest smaller value to 'arr[i]' is 
           the top element of S

    c) push 'arr[i]' onto S
 */

//  NEAREST and closest value on left
vector<int> leftSmaller(int n, int arr[])
{
    stack<int> st;
    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() > arr[i])
        {
            st.pop();
        }

        if (st.empty())
            res.push_back(-1);

        else
            res.push_back(st.top());

        st.push(arr[i]);
    }

    return res;
}

int main()
{
}