#include <stdlib.h>
#include <iostream>
#include <string.h>
#define size 7
using namespace std;

class Node
{
public:
    int key;
    string record;
    Node *next;
    Node()
    {
        key = -1;
        record = "--";
        next = NULL;
    }
    Node(int key, string record)
    {
        this->record = record;
        this->key = key;
        this->next = NULL;
    }
};

class linklist
{
public:
    Node *head;
    Node *h[size];
    linklist()
    {
        for (int i = 0; i < size; i++)
        {
            h[i] = NULL;
        }
    }

    void insert();

    void display();
};

void linklist::insert()
{
    int key;
    string record;
    int hash_value;
    cout << "\nEnter key : ";
    cin >> key;
    cout << "\nEnter record : ";
    cin >> record;

    Node *newnode;
    newnode = new Node(key, record);

    hash_value = key % size;
    Node *temp = h[hash_value];

    if (h[hash_value] == NULL)
    {
        h[hash_value] = newnode;
        return;
    }
    else
    {
        while (temp->next!= NULL)
        {
            temp = temp->next;
        }
         temp->next = newnode;
         return;
    }
   
}

void linklist :: display()
{
    for (int i = 0; i < size; i++)
    {  if(h[i]==NULL){
            cout<<"-->  ";
        cout << "key : NO ";
        
        cout << " rec : NO ";
        cout<<endl;
        cout<<endl;
        }
        else if(h[i]->next==NULL){
        cout<<"-->  ";
        cout << "key : ";
        cout << h[i]->key;
        cout << "  rec : ";
        cout << h[i]->record;
        cout<< endl;cout<<endl;
        }
        // (h[i]->next!= NULL)
        else
        {   Node *temp = h[i];
            while(temp!=NULL){
            cout<<"  -->  ";
            cout << "key : ";
            cout << temp->key;
            cout << "  rec : ";
            cout << temp->record;
            temp = temp->next;
            }
            cout<<endl;cout<<endl;
        }
    }
}


int main()
{
    linklist list;
    char choice;
    cout << "\nInserting in the hash table";
    while (choice != 'n' && choice != 'N')
    {
        list.insert();
        cout << "\nDo you want continue insert :  ";
        cin >> choice;
    }
    cout<<"\nDisplay calling : \n";
    list.display();

    return 0;
}