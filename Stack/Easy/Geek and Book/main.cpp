#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        stack<int> st;

        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            string query;
            cin >> query;

            if (query == "place")
            {
                int number;
                cin >> number;
                st.push(number);
            }

            else
            {
                if (!st.empty())
                {
                    cout << st.top() << endl;
                    st.pop();
                }
                else
                    cout << -1 << endl;
            }
        }
    }
}