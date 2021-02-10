#include <iostream>

using namespace std;

#define MAX 10000

struct Node
{
    int data;
    Node *right, *down;

    Node(int x)
    {
        data = x;
        right = NULL;
        down = NULL;
    }
};

Node *construct(int mat[3][3], int row, int col, int n)
{
    if (row == n || col == n)
        return NULL;

    Node *temp = new Node(mat[row][col]);

    // temp->data = mat[row][col];

    temp->right = construct(mat, row, col + 1, n);
    temp->down = construct(mat, row + 1, col, n);

    return temp;
}

Node *constructLinkedMatrix(int mat[3][3], int n)
{
    Node *head = construct(mat, 0, 0, n);

    return head;
}

void display(Node *temp)
{
    Node *right;
    Node *down = temp;

    while (down)
    {
        right = down;

        while (right)
        {
            cout << right->data << " ";
            right = right->right;
        }
        cout << "\n";
        down = down->down;
    }
}

int main()
{
    int arr[3][3] =
        {{1, 2, 3},
         {4, 5, 6},
         {7, 8, 9}};

    Node *head = constructLinkedMatrix(arr, 3);

    display(head);
}