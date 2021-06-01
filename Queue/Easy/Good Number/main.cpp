#include <iostream>
#include <queue>

using namespace std;

// Good Number : Numbers with only 1,2 as their digits
string good_number_1_2(int n)
{
    queue<string> number;
    number.push("1");
    number.push("2");

    while (n--)
    {
        string curr = number.front();
        number.pop();
        number.push(curr + "1");
        number.push(curr + "2");
    }

    return number.front();
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        cout << good_number_1_2(--n) << "\n";
    }
}