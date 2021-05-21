#include <iostream>
#include <stack>

using namespace std;

// https://www.youtube.com/watch?v=hGl8Boeb7S4

long long getMaxArea(long long arr[], int n)
{
    stack<int> index;
    int max_area = 0;

    for (int i = 0; i < n; i++)
    {
        while (!index.empty() && arr[index.top()] > arr[i])
        {
            int area = 0;
            int index_top = index.top();
            int height = arr[index_top];

            index.pop();
            if (index.empty())
                area = height * i;

            else
                area = height * (i - index_top - 1);

            max_area = max_area > area ? max_area : area;
        }
        index.push(i);
    }

    while (!index.empty())
    {
        int area = 0;

        int index_top = index.top();
        int height = arr[index_top];

        index.pop();
        if (index.empty())
            area = height * n;

        else
            area = height * (n - index_top - 1);

        max_area = max_area > area ? max_area : area;
    }

    return max_area;
}

int main()
{
}