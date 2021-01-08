#include <iostream>

using namespace std;

// The force being equal to the distance (1/d , d being the distance) *******************************
// Read explanation

double search(double low, double high, double magnets[], int n)
{
    double d = 0.0000000000001; // compare to Zero with precission

    double mid = (low + high) / 2.0;
    double force = 0.0;

    for (int i = 0; i < n; i++)
    {
        force += 1.0 / (mid - magnets[i]);
    }

    if (abs(force) < d)
    {
        return mid;
    }

    if (force > 0)
    {
        return search(mid, high, magnets, n);
    }

    else
    {
        return search(low, mid, magnets, n);
    }
}

void nullPoints(int n, double magnets[], double getAnswer[])
{
    for (int i = 0; i < n - 1; i++)
    {
        getAnswer[i] = search(magnets[i], magnets[i + 1], magnets, n);
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    delete[] arr;
}