#include <iostream>

using namespace std;

long long countWays(int n, int k)
{
    long long mod = 1000000007;

    // Single Post
    long long total = k;
    long long same = 0, diff = k;

    for (int i = 2; i <= n; i++)
    {
        same = diff;
        diff = (total * (k - 1)) % mod;
        total = (same + diff) % mod;
    }

    return total;
}

int main()
{
}