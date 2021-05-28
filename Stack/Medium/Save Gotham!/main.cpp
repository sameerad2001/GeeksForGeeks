#include <iostream>
#include <stack>

using namespace std;

int save_gotham(int arr[], int n)
{
    stack<int> st;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            sum += arr[i];
            st.pop();
        }
        st.push(i);
    }

    return sum;
}

int main()
{
}