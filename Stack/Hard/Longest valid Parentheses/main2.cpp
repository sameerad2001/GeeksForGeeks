#include <iostream>
#include <stack>
#include <string>

using namespace std;

int maxLength(string s)
{
    stack<int> st; // Stores indexes
    st.push(-1);

    int maximum = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(i);
        else
        {
            int temp;

            if (!st.empty())
                st.pop();

            if (!st.empty())
            {
                temp = i - st.top();
                maximum = maximum > temp ? maximum : temp;
            }
            else
                st.push(i);
        }
    }

    return maximum;
}

int main()
{
}