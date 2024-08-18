#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define size 7

struct node{
    int key;
    string record;
    struct node * next;
};

struct node *chain[size];
void init(){
    int i;
    for(i=0;i<size;i++){
        chain[i]=NULL;
        //chain[i]->next=NULL;
    }
}

void insert(int key1 ,string record1){
    //new node create
    int hash_value;

    struct node * newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->key=key1;
    newnode->record=record1;
    newnode->next=NULL;

    hash_value=key1%size;
    if(chain[hash_value]==NULL){
        chain[hash_value]=newnode;
    }
    else{
        struct node *temp;
        temp=chain[hash_value];
        while(temp->next!=NULL){
                temp=temp->next;
        }
        temp->next=newnode;
    }

}
/*
void display(){

    int i;
    for(i=0;i<size;i++){
        struct node * temp=chain[i];
        cout<<chain[i];
       
        while(temp){
            cout<<"  "<<temp->key;
            cout<<" "<<temp->record;
            temp=temp->next;


        }
        cout<<"NULL\n";
        
    }
}*/
int main(){
    int key;
    string record;
    init();
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
        {   cout<<"Insert key :\n";
            cin>>key;
            cout<<"insert data:\n";
            cin>>record;

            insert(key,record);

            break;
        }

        case 2:
        {
           // display();
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