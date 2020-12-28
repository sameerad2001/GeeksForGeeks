#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    //t = 1;

    while (t--)
    {
        int n;
        cin >> n;

        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        //***********Left max
        int *leftmax = new int[n];
        leftmax[0] = arr[0];
        leftmax[1] = leftmax[0];

        for (int i = 2; i < n; i++)
        {
            leftmax[i] = max(arr[i - 1], leftmax[i - 1]);
        }

        //***********Right max
        int *rightmin = new int[n];
        rightmin[n - 1] = arr[n - 1];
        rightmin[n - 2] = rightmin[n - 1];

        for (int i = n - 3; i > 0; i--)
        {
            rightmin[i] = min(rightmin[i + 1], arr[i + 1]);
        }

        int f = false;
        for (int i = 1; i < n - 1; i++)
        {
            if (arr[i] >= leftmax[i] && arr[i] <= rightmin[i])
            {
                cout << arr[i] << endl;
                f = true;
                break;
            }
        }

        if (!f)
        {
            cout << -1 << endl;
        }
    }
}
