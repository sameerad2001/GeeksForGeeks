#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> duplicates(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int index = a[i] % n;
        a[index] += n;
    }

    bool flag = true;

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] / n) >= 2)
        {
            ans.push_back(i);
            flag = false;
        }
    }

    if (flag)
        ans.push_back(-1);

    return ans;
}

/* 
vector<int> duplicates(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int index = a[i] % n;
        a[index] += n;
    }

    bool flag = true;

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] / n) >= 2)
        {
            ans.push_back(i);
            flag = false;
        }
    }

    if (flag)
        ans.push_back(-1);

    return ans;
}

*/

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    duplicates(arr, n);

    delete arr;
}