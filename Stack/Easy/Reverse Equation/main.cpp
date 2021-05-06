#include <iostream>
#include <string>
#include <stack>

using namespace std;

// NO STACK NEEDED
string reverseEqn(string s)
{
    stack<int> st;
    string res = "";

    // Reach operator
    int start = 0;
    for (int end = 0; end < s.size(); end++)
    {
        if (s[end] == '+' || s[end] == '-' || s[end] == '*' || s[end] == '/')
        {
            res.insert(res.begin(), s.begin() + start, s.begin() + end);
            //                      [start] --- Term --- [end - 1]

            res.insert(res.begin(), s[end]);
            //                     ending Symbol

            start = end + 1; // New Term
        }
    }

    res.insert(res.begin(), s.begin() + start, s.end());
    //                                Last Term

    return res;
}

int main() {}