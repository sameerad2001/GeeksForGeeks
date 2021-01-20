#include <iostream>
#include <vector>

using namespace std;

int M[10][10];

int columnWithMaxZeros(int n)
{
    int index;
    int max = -1;

    for (int j = 0; j < n; j++)
    {
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[i][j] == 0)
            {
                temp++;
            }
        }

        if (max < temp)
        {
            max = temp;
            index = j;
        }
    }

    return index + 1;
}

int main()
{
}