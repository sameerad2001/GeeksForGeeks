#include <iostream>
#include <stack>

using namespace std;

// Minimum element remaining in stack at pop will be the minimum element inserted till we reached that index
//  20 , 10 ,8 ,19 ,4
//  iteration 0 20 : 20
//  iteration 1 10 : 20 , 10
//  iteration 2 8  : 20 , 10 , 8
//  iteration 3 8  : 20 , 10 , 8 , 8
//  iteration 4 4  : 20 , 10 , 8 , 8 , 4

stack<int> _push(int arr[], int n)
{
    stack<int> minimum_stack;
    int minimum_till_now = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        minimum_till_now = minimum_till_now < arr[i] ? minimum_till_now : arr[i];
        minimum_stack.push(minimum_till_now);
    }

    return minimum_stack;
}
void _getMinAtPop(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;
}

int main()
{
}