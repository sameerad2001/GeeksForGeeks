#include <iostream>
#include <stack>

using namespace std;

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
        int popped = s.top();
        s.pop();

        while (!temp.empty() && popped > temp.top())
        {
            s.push(temp.top());
            temp.pop();
        }

        temp.push(popped);
    }

    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}

int main() {}