#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
    int data;
    struct node * left;
    struct node * right;

};
int main(){
    cout<<"Making Tree by using Link list\n";
    
    //creating first node 
    struct node *r;
    r=(struct node *)malloc(sizeof(struct node));
    r->data=20;
    r->left=NULL;
    r->right=NULL;

    //creating second node
    struct node *p1;
    p1=(struct node *)malloc(sizeof(struct node));
    p1->data=50;
    p1->left=NULL;
    p1->right=NULL;

    //creating third node
    struct node *p2;
    p2=(struct node *)malloc (sizeof(struct node));
    p2->data=90;
    p2->left=NULL;
    p2->right=NULL;

    //creating forth node;
    struct node *p3;
    p3=(struct node *)malloc(sizeof(struct node));
    p3->data=10;
    p3->left=NULL;
    p3->right=NULL;

    //creating fith node;
    struct node *p4;
    p4=(struct node*)malloc(sizeof(struct node));
    p4->data=50;
    p4->left=NULL;
    p4->right=NULL;

    /*    20
        /    \
        50    90
             /   \
            10   50
    
    */
   r->left=p1;
   r->right=p2;
   p2->left=p3;
   p2->right=p4;

   cout<<"\nlink list created sucessfully";



}