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

int virtex[10]; // store vertex

int M[10][10]; // graphs edges store by adjecency matrix

int n; // number of vertex
void mkGraph()
{
    int edge; // if edge then "1" else "0"

    char ans; // if edge then "y" else "n"

    cout << "\nNumber of vertex  : ";
    cin >> n;
    cout << "\nEnter value of vertexes  \n";
    // fill the vertex array
    for (int i = 0; i < n; i++)
    {
        cin >> virtex[i];
    }
    // give edges in matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << virtex[i] << "  and  " << virtex[j] << "  have an edge :  ";
            cin >> ans;
            if (ans == 'y' || ans == 'Y')
            {
                edge = 1;
            }
            else
            {
                edge = 0;
            }
            M[i][j] = edge;
            cout << endl;
            M[i][j] = edge;
        }
    }
}
void display()
{
    cout << "\nThe graphs matrix is like this\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << M[i][j] << "  ";
        }
        cout << endl;
    }
}
// to search index in array for the value
int searchIndex(int value)
{
    for (int m = 0; m < n; m++)
    {
        if (value == virtex[m])
        {
            return m;
        }
    }
}

void BFS(struct queue *head1)
{   struct queue *head=head1;
    int chVirtex[10];//choice of vertex
    cout << endl;
        
        // set all visited vertex as zero;
        for (int i = 0; i < n; i++)
    {
        chVirtex[i] = 0;
    }

    int i;
    head=enqueue(head, virtex[0]);
    chVirtex[0] = 1;

    while (is_empty1() != 1)
    {
        head=dequeue(head);
        cout << dequeuevalue << "  ";
        i = searchIndex(dequeuevalue);
        
        for (int j = 0; j < n; j++)
        {
            if (M[i][j] == 1)
            {
                if (chVirtex[j] != 1)
                {
                   head = enqueue(head, virtex[j]);
                   chVirtex[j]=1;
                }
            }
        }
    }
}

int main()
{
    struct queue *head;
    head = NULL;

    mkGraph();
    display();
    BFS(head);

    return 0;
}
