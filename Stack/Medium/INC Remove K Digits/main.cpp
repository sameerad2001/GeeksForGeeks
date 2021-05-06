#include <iostream>
#include <string>

using namespace std;

// WRONG
string removeKdigits(string S, int k)
{
    int n = S.size();
    int digit_Count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        digit_Count[S[i] - '0']++;
    }

    string partial_Res = "";
    int index = 0;
    for (int i = 0; i < n - k; i++)
    {
        while (digit_Count[index] == 0)
            index++;

        digit_Count[index]--;
        partial_Res += (index + '0');
    }

    string res = "";

    for (int i = 0; i < partial_Res.size(); i++) // Remove 0's from the front
    {
        if (partial_Res[i] == '0')
            continue;
        else
            res += partial_Res[i];
    }

    return res;
}

int main()
{
}