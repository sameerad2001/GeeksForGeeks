// Fizz Buzz
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n = 100;
    string output = "";

    int count_3, count_5;
    count_3 = count_5 = 0;

    for (int number = 1; number <= n; number++)
    {
        count_3++, count_5++;
        string temp = "";

        if (count_3 == 3)
        {
            temp += "fizz";
            count_3 = 0;
        }
        if (count_5 == 5)
        {
            temp += "buzz";
            count_5 = 0;
        }
        if (temp == "")
            temp += to_string(number);

        output += temp + '\n';
    }

    cout << output;

    return 0;
}
