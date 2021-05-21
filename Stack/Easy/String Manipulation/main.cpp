#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int removeConsecutiveSame(vector<string> v)
{
    stack<string> A, B;
    for (int i = 0; i < v.size(); i++)
        A.push(v[i]);

    bool condition = true;
    bool alternate = true;

    while (condition)
    {
        condition = false;

        if (alternate)
        {
            alternate = false;
            while (!A.empty())
            {
                if (!B.empty() && A.top() == B.top())
                {
                    B.pop();
                    condition = true;
                }
                else
                {
                    B.push(A.top());
                }
                A.pop();
            }
        }
        else
        {
            alternate = true;
            while (!B.empty())
            {
                if (!A.empty() && A.top() == B.top())
                {
                    A.pop();
                    condition = true;
                }
                else
                {
                    A.push(B.top());
                }
                B.pop();
            }
        }
    }

    int count = 0;

    while (!A.empty())
    {
        A.pop();
        count++;
    }
    while (!B.empty())
    {
        B.pop();
        count++;
    }

    return count;
}

int main()
{
}