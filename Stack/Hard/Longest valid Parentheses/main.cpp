#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Wrong we need the length of the LONGEST valid substring not the total count of valid '()'
int maxLength(string s)
{
    stack<char> st;
    int maximum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ')' && !st.empty() && st.top() == '(')
        {
            st.pop();
            maximum++;
            continue;
        }
        st.push(s[i]);
    }

    return maximum;
}

int main()
{
}