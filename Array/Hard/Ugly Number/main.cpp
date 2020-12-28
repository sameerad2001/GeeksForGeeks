#include <iostream>

using namespace std;

#define ull unsigned long long

ull divisible(ull n, int divisor)
{
    while (n % divisor == 0)
    {
        n = n / divisor;
    }

    return n;
}

bool isUgly(ull n)
{
    n = divisible(n, 2);
    n = divisible(n, 3);
    n = divisible(n, 5);

    if (n == 1)
    {
        return true;
    }

    return false;
}

ull getNthUglyNo(int n)
{

    if (n == 1)
    {
        return 1;
    }

    ull count = 1;
    //bool flag = true;

    ull i = 1;
    while (count < n)
    {
        i++;

        if (isUgly(i))
        {
            count++;
        }

        // if (count == n)
        // {
        //     flag = false;
        // }
    }

    return i;
}

int main()
{
    int n;
    cin >> n;

    cout << "The required ugly number is: " << getNthUglyNo(n) << endl;
}