#include <iostream>
#include <string >

using namespace std;

string FirstNonRepeating(string A)
{
    string res = "";
    string first = "";
    int index = 0;
    int found[26] = {0};

    for (int i = 0; i < A.length(); i++)
    {
        if (found[A[i] - 'a'] == 0)
        {
            first += A[i];
        }
        found[A[i] - 'a']++;

        while (found[first[index] - 'a'] > 1 && index <= first.length() - 1)
            index++;

        res += index > first.length() - 1 ? '#' : first[index];
    }
    return res;
}

int main()
{
}