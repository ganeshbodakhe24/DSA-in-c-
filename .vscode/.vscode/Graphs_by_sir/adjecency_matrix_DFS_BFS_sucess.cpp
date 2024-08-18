
#include <iostream>
using namespace std;

// functions of queue
int dequeuevalue = 0;
struct queue
{
    int value;
    struct queue *next;
};
struct queue *f = NULL;
struct queue *r = NULL;

int is_empty1()
{
    if (f == r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct queue *enqueue(struct queue *head, int value)
{

    if (head == NULL)
    {
        struct queue *newnode;
        newnode = (struct queue *)malloc(sizeof(struct queue));
        newnode->next = NULL;

        newnode->value = value;
        r = newnode;
        return newnode;
    }

    struct queue *newnode;
    newnode = (struct queue *)malloc(sizeof(struct queue));
    newnode->next = NULL;

    newnode->value = value;
    r->next = newnode;
    r = newnode;
    return head;
}
struct queue *dequeue(struct queue *head)
{
    if (f == r)
    {
        // cout << "\nthe queue is empty";
        return NULL;
    }
    else
    {
        struct queue *temp;
        temp = head;
        // to give out in memory storage;
        dequeuevalue = head->value;
        f = head;
        head = head->next;

        return head;
    }
}
void displayQueue(struct queue *head)
{
    struct queue *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->value;
        cout << "  ";
        ptr = ptr->next;
    }
}
// functions of queue ends;
int numedges, numvertex;
int virtex[10]; // store vertex

int M[10][10]; // graphs edges store by adjecency matrix

int chVirtex[10]; // choice of vertex

// to clear previous data of chVirtex array

void initiate()
{
    for (int i = 0; i < numvertex; i++)
    {
        chVirtex[i] = 0;
    }
}
// make adjecency matrix by user

void undirectedGraph()
{
    int i, j;
    int edge = 1;
    int m = 0;
    while (m != numedges)
    {
        cout << "\nEnter edge vertex first then second : ";
        cin >> i;
        cout << endl;
        cin >> j;

        M[i][j] = edge;
        M[j][i] = edge;
        m++;
    }
}
// to display the adjecency matrix of graph
void display()
{
    for (int i = 0; i < numvertex; i++)
    {
        for (int j = 0; j < numvertex; j++)
        {
            if (M[i][j] >= 10)
            {
                cout << "  " << M[i][j];
            }
            else
            {
                cout << "  0" << M[i][j];
            }
        }
        cout << endl;
    }
}

// BFS search

void BFS(struct queue *head1, int value)
{
    struct queue *head = head1;

    cout << endl;

    // set all visited vertex as zero;
    for (int i = 0; i < numvertex; i++)
    {
        chVirtex[i] = 0;
    }

    int i;
    head = enqueue(head, value); // enqueue of the element
    chVirtex[value] = 1;         // mark as element is visited

    // loop until queue not get empty
    while (is_empty1() != 1)
    {
        head = dequeue(head);
        cout << dequeuevalue << "  "; // printing the dequeue element
        i = dequeuevalue;
        for (int j = 0; j < numvertex; j++)
        {
            if (M[i][j] == 1)
            {
                if (chVirtex[j] != 1)
                {
                    head = enqueue(head, j); // endueue the element
                    chVirtex[j] = 1;         // mark as visited
                }
            }
        }
    }
}

// DFS
void DFS(int value)
{

    chVirtex[value] = 1; // mark as visited

    cout << value << "  "; // printing the element
    for (int j = 0; j < numvertex; j++)
    {
        if (M[value][j] == 1)
        {
            if (chVirtex[j] != 1)
            {
                chVirtex[j] = 1; // mark as visited
                DFS(j);          // calling function again
            }
        }
    }
}
int main()
{
    struct queue *head;
    head = NULL;
    cout << "\nEnter the number of vertex :";
    cin >> numvertex;
    cout << "\nEnter the number of edges : ";
    cin >> numedges;

    undirectedGraph();
    display();

    cout << "\nThe BFS is like this : ";
    cout << endl;
    BFS(head, 0);

    cout << endl;
    cout << "\nThe DFS is like this : ";
    // to delete the visited virtex array
    initiate();
    cout << endl;
    DFS(0);

    return 0;
}
