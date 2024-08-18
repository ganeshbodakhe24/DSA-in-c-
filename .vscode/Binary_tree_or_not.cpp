#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// creating node by function

struct node *create_node(int data)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}



int isBST(struct node * root){
    static struct node * prev =NULL;
    if(root!=NULL){
      if(!isBST(root->left)){
        return 0;
        } 
      if(prev!=NULL&& root->data<=prev->data){
            return 0;
      }
      prev=root;
      return isBST(root->right);


    }
    else{
        return 1;
    }
}

int main()
{
    cout << "creating link list by using function\n";
    struct node *r;
    r = create_node(20);

    struct node *p1;
    p1 = create_node(10);

    struct node *p2;
    p2 = create_node(35);

    struct node *p3;
    p3 = create_node(9);

    struct node *p4;
    p4 = create_node(15);

    struct node *p5;
    p5=create_node(30);
    
    struct node * p6;
    p6=create_node(50);

    /*     20
        /      \
        10      35
      /  \     /   \
      9   15   30   50

    */
    r->left = p1;
    r->right = p2;
    p1->left =p3;
    p1->right=p4;
    p2->left = p5;
    p2->right = p6;

    cout << endl;
    cout << "The link list is created by using function \n";

    if(isBST(r)==1){
        cout<<"The given tree is the binary search tree";
    }
    else{
        cout<<"The given tree is not the binary search tree";
    }

    return 0;
}