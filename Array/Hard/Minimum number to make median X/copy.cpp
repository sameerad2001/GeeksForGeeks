#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int ln = 0, gn = 0, lm = INT_MIN, gm = INT_MAX;
        int hx = 0;
        int a;
        int ret, ret2, ret3;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            if (a == x)
            {
                hx = 1;
                continue;
            }
            else if (a > x)
            {
                gn++;
                gm = min(gm, a);
            }
            else
            {
                ln++;
                lm = max(lm, a);
            }
        }
        ret = abs(gn - ln);
        if (hx || lm + gm == x * 2)
        {
            cout << ret << endl;
        }
        else
        {
            if (lm + gm < x * 2)
                ret2 = abs(gn - ln - 1);
            else
                ret2 = abs(gn - ln + 1);
            ret = min(ret2 + 1, ret + 1);
            cout << ret << endl;
        }
    }
    return 0;
}