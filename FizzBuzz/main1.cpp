// Fizz Buzz
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n = 100;
    string output = "";

    for (int number = 1; number <= n; number++)
    {
        string temp = "";

        if (number % 3 == 0)
            temp += "fizz";
        if (number % 5 == 0)
            temp += "buzz";
        if (temp == "")
            temp += to_string(number);

        output += temp + '\n';
    }

    cout << output;

    return 0;
}
