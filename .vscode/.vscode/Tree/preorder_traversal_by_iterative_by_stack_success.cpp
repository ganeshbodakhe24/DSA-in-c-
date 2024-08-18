#include <iostream>
#include <stdlib.h>
#include <stack>
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

void preorder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->data;
        cout << endl;
        preorder(root->left);

        preorder(root->right);
    }
}
// see book no 2-16
void preorderByStack(struct node *root)
{
    if (root == NULL)
    {
        cout << "\nTree is empty";
        return;
    }
    else
    {
        // make stack
        stack<node *> st;
        st.push(root);
        // st is stack where we are going to sotre the element

        // run till stack is not empty
        while (!st.empty())
        {
            // pop node from stack and print it
            node *curr;
            curr = st.top();
            st.pop();
            cout << curr->data << "  ";
            // push right node
            if (curr->right)
            {
                st.push(curr->right);
            }
            if (curr->left)
            {
                st.push(curr->left);
            }
        }
    }
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

    /*    20
        /    \
        50    90
             /   \
            10   50

    */
    r->left = p1;
    r->right = p2;
    p2->left = p3;
    p2->right = p4;

    cout << endl;
    cout << "The link list is created by using function \n";

    cout << "\npreorder traversing tree\n";
    preorder(r);

    cout << "\npreorder traversing tree by stack";
    preorderByStack(r);
    return 0;
}