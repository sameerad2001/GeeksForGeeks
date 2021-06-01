#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

long long int minSum(int arr[], int n)
{
    sort(arr, arr + n);

    queue<int> digit1, digit2;

    for (int i = 0; i < n; i += 2)
    {
        digit1.push(arr[i]);

        if (i + 1 < n)
            digit2.push(arr[i + 1]);
    }

    long long number1 = 0, number2 = 0;

    while (!digit1.empty())
    {
        int digit = digit1.front();
        digit1.pop();
        number1 = number1 * 10 + digit;
    }

    while (!digit2.empty())
    {
        int digit = digit2.front();
        digit2.pop();
        number2 = number2 * 10 + digit;
    }

    return number1 + number2;
}

int main() {}