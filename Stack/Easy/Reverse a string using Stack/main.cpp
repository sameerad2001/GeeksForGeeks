#include <iostream>
#include <string>
#include <stack>

using namespace std;

char *reverse(char *s, int n)
{
    char *res = new char[n];
    stack<char> st;

    for (int i = 0; s[i] != '\0'; i++)
    {
        st.push(s[i]);
    }

    int i = 0;
    while (!st.empty() && i < n)
    {
        res[i++] = st.top();
        st.pop();
    }

    res[i] = '\0';

    return res;
}

int main()
{
}