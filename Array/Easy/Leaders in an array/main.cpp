#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> leaders(int arr[], int n)
{
    vector<int> leader;
    int max = -1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] >= max)
        {
            leader.push_back(arr[i]);
            max = arr[i];
            //cout << max;
        }
    }

    reverse(leader.begin(), leader.end());

    // int sizevec = leader.size();

    // for (int i = 0; i <= (leader.size() - 1) / 2; i++)
    // {
    //     leader[i] = leader[sizevec - 1 - i] + leader[i];
    //     leader[sizevec - 1 - i] = leader[i] - leader[sizevec - 1 - i];
    //     leader[i] = leader[i] - leader[sizevec - 1 - i];
    // }

    return leader;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> leader = leaders(arr, n);

    for (int i = 0; i < leader.size(); i++)
    {
        cout << leader[i] << " ";
    }

    delete[] arr;
}