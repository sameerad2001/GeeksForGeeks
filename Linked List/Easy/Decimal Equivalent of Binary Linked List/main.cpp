#include <iostream>
#include <math.h>

using namespace std;

const int MOD = 1000000007;

struct Node
{
    bool data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

long long unsigned int decimalValue(Node *head)
{
    // const int MOD = 1000000007;

    long long unsigned int res = 0;

    while (head)
    {
        int value = head->data ? 1 : 0;
        res = ((res << 1) + value) % MOD;

        head = head->next;

        // multiply res by 2 and add value
    }

    return res % MOD;
}

int main()
{
}