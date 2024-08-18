#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    string record;
    struct node *left;
    struct node *right;

};


//creating node by function

struct node * create_node(int data){
    struct node *new_node;
    new_node=(struct  node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
struct node * left_node(struct node *root,struct node *ptr){
    root->left=ptr;
    
    return ptr;
}
int main(){
    
    struct node *root;
    struct node *ptr;
    int  data;

    int ch=1;
    left_node(root,ptr);
    cout<<"This is the programme to create the binarty tree by linked list\n";
    cout<<"\n1)Insert root node\n2)Insert left node\n3)Insert right node\n";
    while(ch!=0){
        cout<<"Enter Choice\n";
        cin>>ch;
        switch(ch){
            case 1:{
                cout<<"\nEnter value  :  ";
                cin>>data;
                root= create_node(data);
                break;
            }
            case 2 :{
                cout<<"Enter parent node : ";
                
                
                cout<<"\n Enter value  :  ";
                cin>>data;
                cout<<left_node(root,ptr);
                break;
            }
            default :{
                cout<<"Wrong choice";
            }
        }
    }
    return 0;
}