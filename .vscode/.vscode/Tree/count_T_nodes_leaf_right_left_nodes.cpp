#include <iostream>
#include <queue>
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
/*
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
*/

int inorderCount(struct node *root)
{
    static int count = 0;
    if (root != NULL)
    {
        inorderCount(root->left);
        // root node
        cout << root->data << "  ";
        count++;
        inorderCount(root->right);
    }
    return count;
}

//count the leaf nodes 
int leafCount(struct node *root)
{
    static int count_leaf = 0;
    if (root != NULL)
    {
        leafCount(root->left);

        // cout<<root->data<<"  ";
        if (root->left == NULL && root->right == NULL)
        {
            count_leaf++;
        }
        leafCount(root->right);
    }
    return count_leaf;
}
int main()
{
    cout << "creating link list by using function\n";
    struct node *r;
    r = create_node(20);

    struct node *p1;
    p1 = create_node(50);

    struct node *p2;
    p2 = create_node(90);

    struct node *p3;
    p3 = create_node(10);

    struct node *p4;
    p4 = create_node(50);

    struct node *p5;
    p5 = create_node(70);

    struct node *p6;
    p6 = create_node(80);

    struct node *p7;
    p7 = create_node(3);

    /*    20
        /      \
       50        90
        \      /   \
        70     10   50
        \           /
         80         3

    */
    r->left = p1;
    r->right = p2;
    p2->left = p3;
    p2->right = p4;
    p1->left = p5;
    p5->right = p6;
    p4->left = p7;

    cout << endl;
    cout << "The link list is created by using function \n";

    cout << "\nInorder traversing tree\n";
    // inorder(r);

    // count total number of nodes
    cout << "\nThe count of total nodes are " << inorderCount(r);

    // count the leaf nodes
    cout << "\nThe count of the leaf nodes are   :  " << leafCount(r);
    return 0;
}