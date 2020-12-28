#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    //t = 1;

    while (t--)
    {
        unsigned int n;
        cin >> n;
        //n = 5;

        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        if (n == 1)
            cout << arr[0] << endl;

        else
        {
            int index;
            if (n % 2 == 0)
            {
                index = floor((n - 2) / 4) + 1;
            }
            else
            {
                index = floor((n - 3) / 4) + 2;
            }

            cout << arr[index] << endl;
        }

        delete[] arr;
    }
}