#include <iostream>
#include <stack>

using namespace std;

// No additional data structures
void deleteMid(stack<int> &s, int sizeOfStack)
{
    deleteInsert(s, sizeOfStack, 0);
}

void deleteInsert(stack<int> &s, int n, int curr)
{
    if (s.empty() || curr == n)
        return;

    int temp = s.top();

    s.pop();

    deleteInsert(s, n, curr + 1);

    if (curr == n / 2)
        return;

    s.push(temp);
}

int main()
{
}