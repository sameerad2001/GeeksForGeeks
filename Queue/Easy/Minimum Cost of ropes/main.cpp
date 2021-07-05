#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

long long minCost(long long arr[], long long n)
{
    // Only one rope => nothing to add
    if (n == 1)
        return 0;

    // MIN Heap or priority queue
    priority_queue<long long, vector<long long>, greater<long long>> cost_temp;
    for (long long i = 0; i < n; i++)
        cost_temp.push(arr[i]);

    long long cost = 0;
    while (cost_temp.size() > 1)
    {
        long long rope_1, rope_2;
        rope_1 = cost_temp.top();
        cost_temp.pop();

        rope_2 = cost_temp.top();
        cost_temp.pop();

        cost += (rope_1 + rope_2);
        cost_temp.push(rope_1 + rope_2);
    }

    return cost;
}

int main()
{
    long long arr[] = {4, 3, 2, 5};
    cout << minCost(arr, 4);
}