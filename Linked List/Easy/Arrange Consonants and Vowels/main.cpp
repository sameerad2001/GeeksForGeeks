#include <iostream>

using namespace std;

struct Node
{
    char data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *arrange(Node *head)
{
    if (head == NULL)
        return head;

    Node *con = new Node('a');
    Node *vow = new Node('a');

    Node *vow_curr = vow;
    Node *con_curr = con;

    Node *curr = head;

    while (curr != NULL)
    {
        char a = curr->data;
        bool is_vow = false;

        if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
            is_vow = true;

        if (is_vow)
        {
            vow_curr->next = curr;
            vow_curr = vow_curr->next;
        }

        else
        {
            con_curr->next = curr;
            con_curr = con_curr->next;
        }

        curr = curr->next;
    }

    con_curr->next = NULL;
    vow_curr->next = con->next;

    head = vow->next;
    return head;
}

int main()
{
}