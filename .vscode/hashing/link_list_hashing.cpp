#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define size 7

struct node
{
    int key;
    string record;
    struct node *next;
};

struct node *head[size] = {NULL};
struct node *chain;

void insert()
{
    int hash_value, key;
    string record;
    cout << "Enter key\n";
    cin >> key;
    cout << "Enter record\n";
    cin >> record;
    hash_value = (key % size);
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->key = key;
    newnode->record = record;
    newnode->next = NULL;

    if (head[hash_value] == NULL)
    {
        head[hash_value] = newnode;
    }
    else
    {
        chain = head[hash_value];
        // cout << "---\n";
        while (chain->next != NULL)
        {
            cout << "-----------\n";
            chain = chain->next;
        }
        chain->next = newnode;
    }
}
void display()
{
    int i;
    cout << "Index\t\t key  \t\tvalue\n";
    cout << "---------------------------------------\n\n";
    for (i = 0; i < size; i++)
    {
        cout << i << "\t\t";
        if (head[i] == NULL)
        {
            cout << "--"
                 << "\t\t"
                 << "--" << endl;
        }
        for (chain = head[i]; chain != NULL; chain = chain->next)
        {
            cout << "\n\t\t" << chain->key << "\t\t" << chain->record << endl;
        }
        cout << "---------------------------------------\n\n";
    }
}

int main()
{
    cout << "link list";
    int ch = 3;
    cout << "1)insert\n2)display\n";
    while (ch != 0)
    {
        cout << "\nEnter choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            insert();
            break;
        }

        case 2:
        {
            display();
            break;
        }
        default:
        {
            cout << "wrong choice\n";
            break;
        }
        }
    }
    return 0;
}