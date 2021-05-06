#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Works
/*
Define a variable left_bnum = 1.
Create a stack right_bnum.
Now, for i = 0 to n-1.
If exp[i] == ‘(‘, then print left_bnum, push left_bnum on to the stack right_bnum and finally increment left_bnum by 1.
Else if exp[i] == ‘)’, then print the top element of the stack right_bnum and then pop the top element from the stack.
*/

vector<int> barcketNumbers(string S)
{
    int open_Bracket_number = 0;
    stack<int> close_Bracket;
    vector<int> res;

    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '(')
        {
            open_Bracket_number++;
            res.push_back(open_Bracket_number);
            close_Bracket.push(open_Bracket_number);
        }
        else if (S[i] == ')')
        {
            res.push_back(close_Bracket.top());
            close_Bracket.pop();
        }
    }

    return res;
}

int main()
{
}