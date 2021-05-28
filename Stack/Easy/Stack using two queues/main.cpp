#include <iostream>
#include <queue>

using namespace std;

class QueueStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int);
    int pop();
};

//Function to push an element into stack using two queues.
void QueueStack ::push(int x)
{
    q1.push(x);

    while (!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }

    // Swap Queues
    queue<int> temp;
    temp = q1;
    q1 = q2;
    q2 = temp;
}

//Function to pop an element from stack using two queues.
int QueueStack ::pop()
{
    int res = -1;

    if (!q2.empty())
    {
        res = q2.front();
        q2.pop();
    }

    return res;
}

int main() {}