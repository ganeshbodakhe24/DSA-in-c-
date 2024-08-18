#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define size 7

// node class to represent
// a dode of linked list
class Node
{
public:
    int key;
    string record;
    Node *next;
    // default constructor
    Node()
    {
        key = 0;
        record = "-";
        next = NULL;
    }
    // parameterised Constructor

    Node(int key, string record)
    {
        this->record = record;
        this->key = key;
        this->next = NULL;
    }
};

// linked list class to implement a linked list

class Linkedlist
{
    Node *head;
    Node *h[size];

public:
    // default constructor
    Linkedlist()
    {
        head = NULL;
        for (int i = 0; i < size; i++)
        {
            h[i] = NULL;
        }
    }
    // function to insert the node
    void insertNode(int, string);

    // function to print the link list
    void printList();

    // function to delete the node at the position
    void deleteNode(int);

    // function to search the node
    void searchNode(int);
};

// function of insert a new node
void Linkedlist::insertNode(int key, string record)
{

    int hash_value = 0;

    // create node
    Node *newnode = new Node(key, record);
    hash_value = key % size;
    // assign to head
    if (h[hash_value] == NULL)
    {
        h[hash_value] = newnode;
        return;
    }
    // traverse till end of list

    Node *temp = h[hash_value];
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

// function to print the nodes of link list
void Linkedlist::printList()
{
    for (int i = 0; i < size; i++)
    {
        Node *temp = h[i];
        // check for empty
        cout << "\n " << i << "\t\t";
        if (h[i] == NULL)
        {
            cout << "list  " << i << " is empty" << endl;
        }
        // traverse the list
        while (temp != NULL)
        {
            cout << temp->key << "  =  ";
            cout << temp->record;
            temp = temp->next;
            if (temp != NULL)
            {
                cout << "  :-->>   ";
            }
        }
        cout << "\n";
    }
}

void Linkedlist::searchNode(int element)
{
    int hash_value;
    hash_value = element % size;
    Node *temp = h[hash_value];
    if (h[hash_value] == NULL)
    {
        cout << "No Record Found\n";
        return;
    }
    // rearching element in sub list
    while (temp != NULL)
    {
        if (temp->key == element)
        {
            cout << "\nKey : " << element;
            cout << "\nRecord : " << temp->record;
            return;
        }
        temp = temp->next;
    }
    // no element found
    cout << "No Record Found\n";
    return;
}

void Linkedlist::deleteNode(int element)
{
    int hash_value;
    hash_value = element % size;
    Node *temp = h[hash_value];
    if (h[hash_value] == NULL)
    {
        cout << "No Record Found\n";
        return;
    }
    // delete first node
    if (h[hash_value]->key == element)
    {
        h[hash_value] = temp->next;
        cout << "\nElement Deleted";
        return;
    }
    // rearching element in sub list
    Node *pre;
    while (temp->key != element || temp->next != NULL)
    {
        pre = temp;
        temp = temp->next;
    }

    if (temp->key == element)
    {
        pre->next = temp->next;
        delete (temp);
        cout << "\nElement Deleted";
    }
    else
    {
        cout << "\nNo element found to delete";
    }
}
int main()
{
    Linkedlist list;
    int ch = 0;
    int key, delete_node, search_element;
    string record;
    cout << "\n1)Insert \n2)Display\n3)Delete\n4)Search\n5)Exit";
    do
    {
        cout << "\nEnter your choice: ";
        ch = 5;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "\nEnter key : ";
            cin >> key;
            cout << "\nEnter record : ";
            cin >> record;
            list.insertNode(key, record);
            break;
        }
        case 2:
        {
            cout << "\nElement in list are : \n";
            list.printList();
            break;
        }
        case 3:
        {
            cout << "\nEnter key of record to be deleted : ";
            cin >> delete_node;
            list.deleteNode(delete_node);
            break;
        }
        case 4:
        {
            cout << "\nEnter key of record to be Searched: ";
            cin >> search_element;
            list.searchNode(search_element);
            break;
        }
        case 5:
        {
            cout << "\nExited";
            break;
        }

        default:
            cout << "\nWrong choice";
            break;
        }

    } while (ch != 5);
    return 0;
}