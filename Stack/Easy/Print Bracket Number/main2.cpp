#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Same but with different variable names
/*
Define a variable left_bnum = 1.
Create a stack right_bnum.
Now, for i = 0 to n-1.
If exp[i] == ‘(‘, then print left_bnum, push left_bnum on to the stack right_bnum and finally increment left_bnum by 1.
Else if exp[i] == ‘)’, then print the top element of the stack right_bnum and then pop the top element from the stack.
*/

vector<int> barcketNumbers(string S)
{
    vector<int> res;
    stack<int> st;
    int count = 0;

    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '(')
        {
            count++;
            st.push(count);
            res.push_back(count);
        }
        else if (S[i] == ')')
        {
            res.push_back(st.top());
            st.pop();
        }
    }

    return res;
}

int main()
{
}