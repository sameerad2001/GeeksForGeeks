#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool ispar(string x)
{
    stack<char> s;

    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == '{' || x[i] == '[' || x[i] == '(')
        {
            s.push(x[i]);
        }
        else
        {
            if (s.empty())
                return false;
            else
            {
                // '(' = 40    ')' = 41
                // '[' = 91    ']' = 93
                // '{' = 123   '}' = 125
                if ((x[i] == 41 || x[i] == 93 || x[i] == 125) && (x[i] - s.top() == 1 || x[i] - s.top() == 2))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }

    if (!s.empty())
        return false;

    return true;
}

int main()
{
}