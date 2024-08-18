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
        cout << "(" << ptr->virtex << ")";
        cout << "  NUM of Near Elements are : ";
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

int main()
{
    Header *head = NULL;
    int a = 0;
   
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

    return 0;
}