#include <iostream>
#include <stack>
#include <string>

using namespace std;

// string transform(string S)
// {
//     stack<int> st;
//     for (int i = 0; i < S.size(); i++)
//     {
//         if (st.empty() || st.top() != S[i])
//         {
//             st.push(1);
//         }
//         if (st.top() == S[i])
//         {
//             int temp = st.top();
//             st.pop();
//             temp++;
//             st.push(temp);
//         }
//     }
// }

string transform(string S)
{
    string res = "";

    for (int i = 0; i < S.size(); i++)
    {
        int count = 0;
        char ch1 = S[i];
        ch1 = tolower(ch1);
        char ch2 = S[i + 1];
        ch2 = tolower(ch2);
        while (ch1 == ch2)
        {
            i++;
            count++;
            ch1 = tolower(S[i]);
            ch1 = tolower(ch1);
            ch2 = tolower(S[i + 1]);
            ch2 = tolower(ch2);
        }

        if (count != 0)
            res += to_string(count) + ch1;
        else
            res += ch1;
    }

    return res;
}

int main()
{
}