#include <iostream>

using namespace std;

// Not Workin
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int *leftMax = new int[n],
            *rightMax = new int[n];

        //left
        leftMax[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (leftMax[i - 1] > arr[i])
            {
                leftMax[i] = leftMax[i - 1];
            }
            else
            {
                leftMax[i] = arr[i];
            }
        }

        //Right
        rightMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i > 0; i--)
        {
            if (rightMax[i + 1] > arr[i])
            {
                rightMax[i] = rightMax[i - 1];
            }
            else
            {
                rightMax[i] = arr[i];
            }
        }

        //check
        //right

        for (int i = 0; i < n - 2; i++)
        {
            if (arr[i] >= rightMax[i])
                cout << arr[i] << " ";
        }
        cout << arr[n - 1] << endl;

        //left
        cout << arr[0] << endl;
        for (int i = 1; i < n - 1; i++)
        {
            if (arr[i] >= leftMax[i])
                cout << arr[i] << " ";
        }

        cout << endl;
        delete[] arr;
    }
}