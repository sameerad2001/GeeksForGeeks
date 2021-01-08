#include <iostream>

using namespace std;

// Requires 0-1 knapsack
struct Subject
{
    int time;
    int marks;
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;    // no of topics
        int h, p; //Time left and passing marks

        cin >> n >> h >> p;

        Subject *s = new Subject[n];

        for (int i = 0; i < n; i++)
        {
            cin >> s->time;
            cin >> s->marks;
        }

        delete[] s;
    }
}