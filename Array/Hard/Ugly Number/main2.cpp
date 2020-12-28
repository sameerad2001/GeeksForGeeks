#include <iostream>
#include <algorithm>

using namespace std;

#define ull unsigned long long

ull getNthUglyNo(int n)
{
    if (n == 1)
    {
        return 1;
    }

    ull *ugly = new ull[n];
    ugly[0] = 1;

    int count = 1;
    int i2, i3, i5;
    i2 = i3 = i5 = 0; //inex

    ull next2, next3, next5, next;

    while (count < n)
    {
        next2 = ugly[i2] * 2;
        next3 = ugly[i3] * 3;
        next5 = ugly[i5] * 5;

        next = min(next2, next3);
        next = min(next, next5);

        if (next == next2)
        {
            i2++;
        }

        if (next == next3)
        {
            i3++;
        }

        if (next == next5)
        {
            i5++;
        }

        ugly[count] = next;
        count++;
    }

    return ugly[n - 1];
}

int main()
{
    int n;
    cin >> n;

    cout << "The required number is: " << getNthUglyNo(n) << endl;
}