#include <iostream>
using namespace std;

struct queue
{
    char value;
    struct queue *next;
};

struct queue *r = NULL;

struct queue *insert(struct queue *head)
{
    char value;
    if (head == NULL)
    {
        struct queue *newnode;
        newnode = (struct queue *)malloc(sizeof(struct queue));
        newnode->next = NULL;
        cout << "\nEnter value";
        cin >> value;
        newnode->value = value;
        r = newnode;
        return newnode;
    }

    struct queue *newnode;
    newnode = (struct queue *)malloc(sizeof(struct queue));
    newnode->next = NULL;
    cout << "\nEnter value";
    cin >> value;
    newnode->value = value;
    r->next = newnode;
    r = newnode;
    return head;
}

void display(struct queue *head)
{
    struct queue *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->value;
        cout << "  ";
        ptr = ptr->next;
    }
}
int main()
{   int numvirtex;
    struct queue *head;
    head = NULL;
    cout<<"Enter the number of the virtises";;
    cin>>numvirtex;
    int i=1;
    while(i<numvirtex){
        head=insert(head);
        i++;

    }
        return 0;
}