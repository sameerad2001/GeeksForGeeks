#include <iostream>
#include <algorithm>

using namespace std;

//*********************
//Requires Vector pairs
//Quick Sort
void convert(int arr[], int n)
{

    int *aux = new int[n];

    int maximum = arr[0];
    for (int i = 1; i < n; i++)
    {
        maximum = max(maximum, arr[i]);
    }

    maximum++;

    for (int i = 0; i < n; i++)
    {
        aux[i] = arr[i] + i * maximum;
    }

    // Sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (aux[i] % maximum < aux[i] % maximum)
            {
                swap(aux[i], aux[j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[aux[i] / maximum]=i;
    }

    delete[] aux;
}

int main()
{
}