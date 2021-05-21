#include <iostream>
#include <stack>

#define MAX 10000

using namespace std;

int max_area_histogram(int arr[], int n)
{
    int max_area = 0;
    int last_pos_with_elm = 0;

    stack<int> index, height;

    for (int i = 0; i < n; i++)
    {
        last_pos_with_elm = 10000000;

        while (!index.empty() && arr[i] < height.top())
        {
            last_pos_with_elm = index.top();

            int height_top = height.top();
            int index_top = index.top();
            index.pop();
            height.pop();

            int temp = height_top * (i - index_top - 1);

            max_area = max_area > temp ? max_area : temp;
        }

        if (index.empty() || arr[i] >= height.top())
        {
            height.push(arr[i]);
            index.push(min(last_pos_with_elm, i));
        }
    }

    while (!index.empty())
    {
        int temp = (n - index.top()) * height.top();
        max_area = max_area > temp ? max_area : temp;

        index.pop();
        height.pop();
    }

    return max_area;
}

int maxArea(int arr[MAX][MAX], int n, int m)
{
    int histogram[m] = {0};

    int max_area = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
                histogram[j] += 1;

            else
                histogram[j] = 0;
        }

        int temp = max_area_histogram(histogram, m);
        max_area = max_area > temp ? max_area : temp;
    }

    return max_area;
}

int main() {}