#include <iostream>
#include <stack>

using namespace std;

// https://insidecode.teachable.com/blog/208014/sort-stack

class SortedStack
{
public:
    stack<int> s;
    void sort();
};

void SortedStack ::sort()
{
    stack<int> temp;

    while (!s.empty())
    {
        int poped_elm = s.top();
        s.pop();

        while (!temp.empty() && poped_elm < temp.top())
        {
            s.push(temp.top());
            temp.pop();
        }

        temp.push(poped_elm);
    }

    // put the elements back into the original stack
    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}

int main()
{
}