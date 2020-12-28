#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    //cin >> t;
    t = 1;
    while (t--)
    {
        string s = " aabcbcdbca";
        //cin >> s;

        //******** COUNT DISTINCT ELEMENTS **********

        int *visited = (int *)calloc(26, sizeof(int)); // calloc every element to initializes to zero

        for (int i = 0; i < s.length(); i++)
        {
            int index = s[i] - 97; // ASCII a = 97
            if (visited[index] == 0)
            {
                visited[index] = 1;
            }
        }

        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            if (visited[i] == 1)
            {
                count++;
                visited[i] = 0;
            }
        }
        //cout << count << endl;

        //******** SMALLEST WINDOW **********

        int count2 = 0;

        int start = 0, end = s.length() - 1;

        bool f = true;

        for (int i = 0; i < s.length(); i++)
        {
            int index = s[i] - 97; // ASCII a = 97

            visited[index]++;
            count2++;
        }

        while (f)
        {
            int indexs = s[start] - 97;
            int indexe = s[end] - 97;

            if (visited[indexs] == 1 && visited[indexe] == 1)
            {
                f = false;
                break;
            }

            else if (visited[indexs] > 1)
            {
                visited[indexs]--;
                start++;
            }

            else if (visited[indexe] > 1)
            {
                visited[indexe]--;
                end--;
            }
        }

        for (int i = start; i < end; i++)
        {
            cout << s[i];
        }

        free(visited);
    }
}