#include <iostream>
#include <stack>
#include <string>

using namespace std;

class TwoStacks
{
    int *arr;
    int size;
    int top1 = -1, top2 = size;

public:
    void push1(int x);
    void push2(int x);
    int pop1();
    int pop2();
};

void TwoStacks ::push1(int x)
{
    arr[++top1] = x;
}

void TwoStacks ::push2(int x)
{
    arr[--top2] = x;
}

int TwoStacks ::pop1()
{
    if (top1 == -1)
        return -1;

    int res = arr[top1--];
    return res;
}

int TwoStacks ::pop2()
{
    if (top2 == size)
        return -1;

    int res = arr[top2++];
    return res;
}

int main()
{
}