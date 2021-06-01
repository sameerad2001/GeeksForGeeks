#include <iostream>
#include <stack>

using namespace std;

class StackQueue
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    void push(int);
    int pop();
};

// Valid Soln but not passing
void StackQueue ::push(int x)
{
    s1.push(x);

    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }

    //  Not working V
    // stack<int> temp = s1;
    // s1 = s2;
    // s2 = temp;

    s1.swap(s2);
}

int StackQueue ::pop()
{
    if (s2.empty())
        return -1;

    int res = s2.top();
    s2.pop();

    return res;
}