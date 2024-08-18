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

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data;
        cout << endl;
        inorder(root->right);
    }
}

struct node * inorderPrdecessor(struct node * root){
        root=root->left;
        while(root->right!=NULL){
            root=root->right;

        }
        return root;
}

struct node * deleteNode(struct node* root , int value){
    struct node *ipre;
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    //searching for node
    if(value<root->data){
        root->left=deleteNode(root->left,value);
    }
    else  if(value>root->data){
        root->right=deleteNode(root->right,value);
    }
    else{
        //delete
        ipre=inorderPrdecessor(root);
        root->data=ipre->data;
        root->left=deleteNode(root->left,ipre->data);

    }
    return root;
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

    cout<<"\nInorder traversal in BST"<<endl;
   inorder(r);

   cout<<"delete ";
    deleteNode(r,20);
    
    cout<<endl;inorder(r);

   
    return 0;
}