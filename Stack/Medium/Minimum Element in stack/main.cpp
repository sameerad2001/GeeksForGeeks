#include <iostream>
#include <stack>

using namespace std;

// O(1) Time
// O(n) space ---> Can be more efficient

class _stack
{
    stack<int> s;
    int minEle;

public:
    int getMin();
    int pop();
    void push(int x);
};

stack<int> minimum_element;

int _stack ::getMin()
{
    if (s.empty())
        return -1;

    minEle = minimum_element.top();

    return minEle;
}

int _stack ::pop()
{
    if (s.empty())
        return -1;

    int value = s.top();

    s.pop();
    minimum_element.pop();

    minEle = minimum_element.top();

    return value;
}

void _stack::push(int x)
{
    s.push(x);
    if (minimum_element.empty() || minimum_element.top() > x)
        minimum_element.push(x);
    else
        minimum_element.push(minimum_element.top());

    minEle = minimum_element.top();
}

int main()
{
}