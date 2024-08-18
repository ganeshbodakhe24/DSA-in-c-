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

    while (ch!=6)
    {
        cout << "\n1)Insert root 2) Insert node 3) Inorder Traversal 4)preorder Traversal 5)Postorder Traversal 6)Exit  ";
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
            cout << "\nInorder Traversal :\n";
            inorder(r);
            
            break;
        }
        case 4: {
            cout << "\nPreorder Traversal :\n";
            preorder(r);
            break;
            
            
        }
        case 5:{
            cout << "\nPostorder Traversal :\n";
            postorder(r);
           
            break;
        }
        case 6:{
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