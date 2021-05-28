#include <iostream>
#include <stack>
#include <string>

using namespace std;

string Reduced_String(int k, string s)
{

    struct char_count
    {
        char element;
        int count;
    };
    stack<char_count> st;

    for (int i = 0; i < s.size(); i++)
    {
        char element = s[i];
        int count = 1;

        if (!st.empty() && st.top().element == s[i])
            count = st.top().count + 1;

        char_count temp = {s[i],
                           count};

        st.push(temp);

        // cout << st.top().element << st.top().count << endl;
        if (st.top().count == k)
        {
            for (int j = 0; j < k; j++)
            {
                st.pop();
            }
        }
    }

    string res = "";

    while (!st.empty())
    {
        res += st.top().element;
        st.pop();
    }

    // reverse (res.begin(),res.end());

    int n = res.size();
    for (int i = 0; i < n / 2; i++)
    {
        char temp = res[i];
        res[i] = res[n - 1 - i];
        res[n - 1 - i] = temp;
    }

    return res;
}

int main()
{
}