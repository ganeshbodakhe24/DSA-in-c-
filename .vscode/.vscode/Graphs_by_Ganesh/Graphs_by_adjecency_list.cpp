#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct header
{
    string virtex;
    struct header *down;
};

struct near
{
    string virtex;
    struct header *next;
};

struct header *insert(struct header *head)
{
    string virtex;

    cout << "\nEnter the virtex -  ";
    cin >> virtex;
    if (head == NULL)
    {
        struct header *ptr;
        ptr = (struct header *)malloc(sizeof(struct header));
        ptr->virtex = virtex;
        ptr->down = NULL;
        head = ptr;
        return ptr;
    }
    else
    {

        cout << "\nEnter the virtex -  ";
        cin >> virtex;
        struct header *nextvirtex;
        nextvirtex = (struct header *)malloc(sizeof(struct header));

        nextvirtex->virtex = virtex;
        nextvirtex->down = NULL;
        while (head->down != NULL)
        {
            head = head->down;
        }
        head->down = nextvirtex;
    }
    return head;
}

void display(struct header *head)
{
    if (head == NULL)
    {
        cout << "\n Plese make adjecency list first ";
        return;
    }
    else
    {
        while (head != NULL)
        {
            cout << head->virtex;
            cout << endl;
            head = head->down;
        }
    }
}

int main()
{

    int numedges; // its return number of edges

    cout << "\nThis is the programme of adjecency list print of the grph (undirected)";
    struct header *head = NULL;

    cout << "\nEnter the number of edges";
    cin >> numedges;
    int i = 1;
    while (i != numedges)
    {
        head = insert(head);
        i++;
    }

    return 0;
}