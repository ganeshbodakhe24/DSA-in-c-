#include <iostream>
using namespace std;


struct node
{
    int data;
    struct node *left;
    struct node *right;
};

//root node insert
struct node *insertRoot()
{
    int data;
    cout << "\nEnter the root node  : ";
    cin >> data;
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

//insertion of other nodes
void insertion(struct node *root)
{
    int value;
    cout << "\nInsert the data  : ";
    cin >> value;

    //creating new node
    struct node *prev = NULL;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = value;
    ptr->left = NULL;
    ptr->right = NULL;

    //inserting new node in BST
    while (root != NULL)
    {
        prev = root;
        if (value == root->data)
        {
            cout << "You cant insert in tree duplication occured!!!!!!!";
            break;
        }
        else if (root->data < value)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    if (value < prev->data)
    {
        prev->left = ptr;
    }
    else
    {
        prev->right = ptr;
    }
}

// finding inorder Sucessor for delete node 
struct node * inorderSucessor(struct node * root){
        root=root->right;
        while(root->left!=NULL){
            root=root->left;

        }
        return root;
}


struct node * deleteNode(struct node* root , int value){
    struct node *ipost;
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
        ipost=inorderSucessor(root);
        root->data=ipost->data;
        root->right=deleteNode(root->right,ipost->data);

    }

    return root;
}

//print inorder 
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data;
        cout << "  ";
        inorder(root->right);
    }
}

//print preorder
void preorder(struct node *root)
{
    if (root != NULL)
    {

        cout << root->data;
        cout << "  ";
        preorder(root->left);
        preorder(root->right);
    }
}

//print postorder
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data;
        cout << "  ";
    }
}

int main()
{
    cout << "Creating link list by using function\n";
    int ch = 2;
    int data;
    struct node *r;

    while (ch!=5)
    {
        cout << "\n1)Insert root 2) Insert node 3)Display 4)Delete 5)Exit  ";
        cout << "\nChoice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            // insert root
            r = insertRoot();
            break;
        }
        case 2:
        {
            insertion(r);
            break;
        }
        case 3:
        {
            cout << "\nInorder display :\n";
            inorder(r);
            cout << "\nPreorder display :\n";
            preorder(r);
            cout << "\nPostorder display :\n";
            postorder(r);
            break;
        }
        case 4: {
            cout<<"\nEnter the node  : ";
            cin>>data;
            deleteNode(r,data);
            cout<<"\nNode is deleted";
            break;
        }
        case 5:{
            cout<<"\nExit";
            break;
        }
        default:
        {
            cout << "\nWrong choice !!!";
        }
        }
    }

    return 0;
}