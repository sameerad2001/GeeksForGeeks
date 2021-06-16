//  PRACTICE
#include <iostream>

using namespace std;

int kadane(int arr[], int n)
{
    int temp = 0, max_sum = 0;

    for (int i = 0; i < n; i++)
    {
        temp += arr[i];

        if (temp > max_sum)
            max_sum = temp;

        temp = temp < 0 ? 0 : temp;
    }

    return max_sum;
}

int circularSubarraySum(int arr[], int n)
{
    int total_sum = 0, min_sum, max_sum;

    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
        arr[i] *= -1;
    }

    min_sum = kadane(arr, n);
    min_sum *= -1; // Negate

    max_sum = total_sum - min_sum;
    return max_sum;
}

int main()
{
    int arr[5] = {-8, 8, 10, -11, 12};
    cout << circularSubarraySum(arr, 5) << "\n";
    // Answer should be 22 : -8 + 8 + 10 + 12
}