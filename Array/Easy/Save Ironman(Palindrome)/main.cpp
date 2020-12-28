#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    //t = 1;

    cin.ignore();

    while (t--)
    {

        string s;

        getline(cin, s);

        //scanf("%[^\n]%*c", s);
        //s = "abc$CbA"; //arr = A B C C B A

        int *arr = new int[s.length()];

        int j = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z') // ASCII A = 65
            {
                arr[j] = s[i];
                j++;
            }

            else if (s[i] >= 'a' && s[i] <= 'z')
            {
                arr[j] = (s[i] - 'a' + 'A'); // 97 - 65 = 32 (NOT CASE SENSITIVE)*******
                j++;
            }

            else if (s[i] >= '0' && s[i] <= '9')
            {
                arr[j] = s[i];
                j++;
            }
        }

        // for (int i = 0; i < j / 2; i++)
        // {
        //     cout << arr[i] << " " << arr[j - 1 - i] << endl;
        // }

        bool f = true;

        for (int i = 0; i <= j / 2; i++)
        {
            if (arr[i] != arr[j - i - 1])
            {
                f = false;
            }
        }

        if (f)
        {
            cout << "YES" << endl;
        }

        else
        {
            cout << "NO" << endl;
        }

        delete arr;
        //  cout << s << endl;
    }
}
