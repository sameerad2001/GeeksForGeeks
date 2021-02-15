#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

bool compute(Node *root)
{
    string str = "";

    Node *temp = root;
    while (temp)
    {
        str.append(temp->data);
        temp = temp->next;
    }

    int length = str.length();
    for (int i = 0; i < length; i++)
    {
        if (str[i] != str[length - 1 - i])
            return false;
    }

    return true;
}

int main()
{
}