#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>

#define pb push_back

using namespace std;

int *span;

/*
vector<int> calculateSpan(int price[], int n)
{

    vector<int> span;
    stack<int> stack;

    span.push_back(1);
    stack.push(0);

    for (int i = 1; i < n; i++)
    {
        while (!stack.empty() && price[stack.top()] <= price[i])
        {
            stack.pop();
        }

        span.push_back(stack.empty() ? i + 1 : i - stack.top()); // if stack is empty price[i] is highest till now

        stack.push(i);
    }
    
    return span;

}
*/

void calculateSpan(int price[], int n)
{
    stack<int> stack;

    span[0] = 1;
    stack.push(0);

    for (int i = 1; i < n; i++)
    {
        while (!stack.empty() && price[stack.top()] < price[i])
        {
            stack.pop();
        }

        span[i] = stack.empty() ? i + 1 : i - stack.top(); // if stack is empty price[i] is highest till now

        stack.push(i);
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = (int *)malloc(n * sizeof(int));

    span = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    calculateSpan(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << span[i] << " ";
    }

    free(arr);
    delete span;
}