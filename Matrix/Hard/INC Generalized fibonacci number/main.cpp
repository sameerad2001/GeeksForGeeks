#include <iostream>
#include <vector>

using namespace std;

long long genFibNum(long long a, long long b, long long c, long long n, long long m)
{
    vector<vector<long long>> aux;

    vector<long long> temp;

    temp.push_back(a);
    temp.push_back(b);
    aux.push_back(temp);

    temp.pop_back();
    temp.pop_back();
    temp.push_back(1);
    temp.push_back(0);
    aux.push_back(temp);
}

int main()
{
}