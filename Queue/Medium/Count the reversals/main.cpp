#include <iostream>
#include <stack>

using namespace std;

int countRev(string s)
{
    int n = s.length();
    if (n % 2 != 0) // length ODD => Can't pair the brackets
        return -1;

    int open_count = 0;
    int close_count = 0;

    stack<char> open_bracket_stack;

    stack<char> &obs = open_bracket_stack;
    for (int i = 0; i < n; i++)
    {
        char curr = s[i];

        if (curr == '{')
        {
            open_bracket_stack.push(curr);
            open_count++;
        }
        else if (curr == '}' && !obs.empty() && obs.top() == '{')
        {
            obs.pop();
            open_count--;
        }
        else
        {
            close_count++;
        }
    }

    // } { { { =>
    // 1. } {  '{ }'    count = 1
    // 2. '{ }'         count = 1 + 2

    if (open_count % 2 == 0)
        open_count = (open_count / 2) + 1;
    else
        open_count = open_count / 2;

    if (close_count % 2 == 0)
        close_count = (close_count / 2) + 1;
    else
        close_count = close_count / 2;

    return open_count + close_count;
}

int main()
{
}