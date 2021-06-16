#include <iostream>

using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n)
{
    int total_dist = 0, total_petrol = 0;
    for (int i = 0; i < n; i++)
    {
        total_petrol += p[i].petrol;
        total_dist += p[i].distance;
    }

    if (total_petrol - total_dist < 0)
        return -1;

    int start, capacity, deficit;
    start = capacity = deficit = 0;

    for (int i = 0; i < n; i++)
    {
        capacity += p[i].petrol - p[i].distance;

        if (capacity < 0)
        {
            deficit += capacity;
            capacity = 0;
            start = i + 1;
        }
    }

    return capacity - deficit < 0 ? -1 : start;
}

int main()
{
}