#include <iostream>
#include <string>

using namespace std;

struct Node
{
    char data;
    Node *next;

    Node(char data)
    {
        this->data = data;
        next = NULL;
    }
};

string
FirstNonRepeating(string A)
{
    string res = "";
    int hasOccurred[26] = {0};

    char first = A[0];
    res += first;
    hasOccurred[A[0] - 'a']++;

    int hasBeenAccounted[26] = {0};

    Node *head;

    for (int i = 1; A[i] != 0; i++)
    {
        if (hasOccurred[A[i] - 'a'] == 1)
        {
            char value;
            Node *temp = head;

            if (value != head->data)
            {
                if (hasBeenAccounted[A[i] - 'a'])
                {
                    value = head->data;
                    while (temp->next->data != value)
                    {
                        temp = temp->next;
                    }
                    Node *del = temp->next;
                    temp->next = del->next;
                    delete (del);
                }
                else
                {
                                }
            }

            else
            {
            }

            res += value;
        }
    }
}

int main()
{
    string str = FirstNonRepeating("Hello");
    cout << str;
}