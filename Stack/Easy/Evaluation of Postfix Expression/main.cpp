#include <iostream>
#include <string>
#include <stack>

using namespace std;

int evaluatePostfix(string S)
{
    if (S.size() == 0)
    {
        return -1;
    }

    stack<int> st;

    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] >= '0' && S[i] <= '9')
        {
            int item = S[i] - '0';
            st.push(item);
        }
        else
        {
            char operation = S[i];
            int result;

            int operand_2 = st.top();
            st.pop();
            int operand_1 = st.top();
            st.pop();

            switch (operation)
            {
            case '+':
                result = operand_1 + operand_2;
                break;

            case '-':
                result = operand_1 - operand_2;
                break;

            case '*':
                result = operand_1 * operand_2;
                break;

            case '/':
                result = operand_1 / operand_2;
                break;
            }

            st.push(result);
        }
    }

    if (st.empty())
        return -1;

    return st.top();
}

int main()
{
    cout << evaluatePostfix("231*+9-");
}