#include <iostream>

using namespace std;

struct Node
{
    char c;
    struct Node *next;

    Node(char x)
    {
        c = x;
        next = NULL;
    }
};

int compare(Node *list1, Node *list2)
{

    while (list1 && list2)
    {
        if (list1->c > list2->c)
            return 1;
        else if (list1->c < list2->c)
            return -1;

        list1 = list1->next, list2 = list2->next;
    }

    if (list1)
        return 1;

    else if (list2)
        return -1;

    return 0;
}

int main() {}