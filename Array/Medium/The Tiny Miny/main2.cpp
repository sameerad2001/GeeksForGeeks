#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, n;
        cin >> a >> n;

        // 0 - 9
        int digitCount[10] = {0};

        for (int i = 0; i < n; i++)
        {
            int value;
            value = pow(a, i + 1);

            while (value % 10 != 0)
            {
                if (value % 10 != 0)
                    digitCount[value % 10]++;

                value /= 10;
            }
        }

        for (int i = 1; i < 10; i++)
        {
            while (digitCount[i] != 0)
            {
                cout << i;
                digitCount[i]--;
            }
        }

        cout << endl;
    }
}