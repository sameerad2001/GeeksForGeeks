#include <iostream>
#include <stack>

using namespace std;

// {"12", "21", "34", "43", "56", "65", "78", "87", "09", "90"}
int compute_pair(char second_char)
{
    switch (second_char)
    {
    case '0':
        return '9';
    case '9':
        return '0';

    case '1':
        return '2';
    case '2':
        return '1';

    case '3':
        return '4';
    case '4':
        return '3';

    case '5':
        return '6';
    case '6':
        return '5';

    case '7':
        return '8';
    case '8':
        return '7';

    default:
        break;
    }
    return -1;
}

int minLength(string s, int n)
{
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (!st.empty())
        {
            int comp1 = compute_pair(s[i]);

            if (st.top() == comp1)
            {
                st.pop();
                continue;
            }
        }

        st.push(s[i]);
    }

    return st.size();
}

int main()
{
    int ans = minLength("8734344344334521", 16);
    cout << ans;
}