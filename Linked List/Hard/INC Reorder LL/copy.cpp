#include <bits/stdc++.h>
using namespace std;

// Linkedlist Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Function to create newNode in a linkedlist
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

// Function to print the linked list
void printlist(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        if (head->next)
            cout << "-> ";
        head = head->next;
    }
    cout << endl;
}

void rearrange(Node *head)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p = head;

    vector<struct Node *> v;
    int l, i;

    while (p != NULL)
    {
        v.push_back(p);
        p = p->next;
    }
    l = v.size();
    p = head;

    for (i = 0; i < l / 2; i++)
    {
        if (i != 0)
        {
            p->next = v[i];
            p = p->next;
        }
        p->next = v[l - i - 1];
        p = p->next;
    }

    if (l % 2 == 1)
    {
        p->next = v[i];
        p = p->next;
    }
    p->next = NULL;
}

// Driver program
int main()
{
    Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printlist(head); // Print original list
    rearrange(head); // Modify the list
    printlist(head); // Print modified list
    return 0;
}