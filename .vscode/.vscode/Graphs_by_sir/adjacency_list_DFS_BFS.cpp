#include <iostream>
using namespace std;

// struct of the list
char arr[10];//to store the char virtex into arr
int numvirtex;//number of virtex
int M[10][10];//matrix

int initiate()
{
    for (int i = 0; i < numvirtex; i++)
    {
        for (int j = 0; j < numvirtex; j++)
        {
            M[i][j] = 0;
        }
    }
}

class Header
{
public:
    char virtex;
    Header *next; // next pointer of the list
    Header *down; // down pinter of the header pointer
};

void mkHeaderList(Header **head_ref)
{
    Header *ptr;
    // if the head pointer is NULL
    if (*head_ref == NULL)
    {
        Header *newnode = new Header();
        newnode->down = NULL;
        cout << "Enter virtex  ";
        cin >> newnode->virtex;
        (*head_ref) = newnode;
        ptr = newnode;
    }
    // if head pinter not NULL
    else
    {
        Header *newnode = new Header();
        newnode->down = NULL;
        cout << "Enter virtex  ";
        cin >> newnode->virtex;
        ptr->down = newnode;
        ptr = newnode;
    }
}
void addAdjectElement(Header **head_ref)
{
    Header *ptr = (*head_ref); // down pter
    int elements;              // number of near virtex present in header virtex
    
    // to travel through head nodes
    while (ptr != NULL)
    {
        Header *adjecent = ptr;
       
        cout << " How many adjacent nodes of  : ";
         cout << "(" << ptr->virtex << ")";
         cout<<"  is present :  ";
        cin >> elements;

        // to travel through the adjecent nodes
        while (elements != 0)
        {
            Header *newnode = new Header();
            cout << "Enter Virtex  ";
            cin >> newnode->virtex;
            newnode->next = NULL;
            adjecent->next = newnode;
            adjecent = newnode;
            elements--;
        }
        ptr = ptr->down;
    }
}

void display(Header **head_ref)
{
    Header *ptr;
    ptr = (*head_ref);
    while (ptr != NULL)
    {
        cout << endl
             << ptr->virtex;
        ptr = ptr->down;
    }
}
void displayList(Header **head_ref)
{
    Header *ptr = (*head_ref); // down pter

    // travel through the header nodes
    while (ptr != NULL)
    {
        Header *adjecent = ptr->next;
        cout << ptr->virtex << "  --- ";

        // travel through adjecent nodes
        while (adjecent != NULL)
        {
            cout << "->  " << adjecent->virtex << " ";
            adjecent = adjecent->next;
        }
        ptr = ptr->down;
        cout << endl;
    }
}

//add virtex in array
void addVirtexInArr(Header **head_ref)
{  int i=0;
    Header *ptr;
    ptr = (*head_ref);
    while (ptr != NULL)
    {
        arr[i]=ptr->virtex;
        ptr = ptr->down;
        i++;
    }
}

// to search index in array for the value
int search(int value)
{
    for (int m = 0; m < numvirtex; m++)
    {
        if (value == arr[m])
        {
            return m;
        }
    }
}

/*
int search(char val){
    int i=0;
    while(arr[i]!=val){
    i++;
    }
    return i-1;
}
*/

//to print the adjecency matrix
void adjecenyMatrix(Header **head_ref){
    int i,j;
    Header *ptr = (*head_ref); // down pter

    // travel through the header nodes
    while (ptr != NULL)
    {
        Header *adjecent = ptr->next;
        i=search(ptr->virtex);
        
        // travel through adjecent nodes
        while (adjecent != NULL)
        {
            j=search(adjecent->virtex);
            M[i][j]=1;
            M[j][i]=1;
            adjecent = adjecent->next;
        }
        ptr = ptr->down;
        cout << endl;
    }
}

//is visited or not
void BFS(Header *head){
    Header *ptr=head;
    

}
void displayMatrix()
{
    for (int i = 0; i < numvirtex; i++)
    {
        for (int j = 0; j < numvirtex; j++)
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
//queue

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

//int M[10][10]; // graphs edges store by adjecency matrix

int chVirtex[10]; // choice of vertex

// to clear previous data of chVirtex array

// make adjecency matrix by user


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
        cout<<arr[dequeuevalue];
        //cout << dequeuevalue << "  "; // printing the dequeue element
        i = dequeuevalue;
        for (int j = 0; j < numvirtex; j++)
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

    cout << arr[value] << "  "; // printing the element
    for (int j = 0; j < numvirtex; j++)
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
    Header *head = NULL;
    int a = 0;
   struct queue *queuehead;
    queuehead = NULL;

    cout << "\nEnter virtex Number  ";
    cin >> numvirtex;
    while (a < numvirtex)
    {
        mkHeaderList(&head);
        a++;
    }
    addAdjectElement(&head);
    // display(&head);
    displayList(&head);
    addVirtexInArr(&head);
    initiate();
    adjecenyMatrix(&head);
    displayMatrix();
    for(int i=0;i<numvirtex;i++){
        cout<<arr[i];
    }
    BFS(queuehead,0);
    DFS(0);

    return 0;
}