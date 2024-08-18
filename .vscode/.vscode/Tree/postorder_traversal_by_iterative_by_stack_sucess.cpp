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

void postorder(struct node *root)
{
    if (root != NULL)
    {

        postorder(root->left);
        postorder(root->right);
        cout << root->data;
        cout << endl;
    }
}

void postOrderByStack(struct node *root)
{
    if (root == NULL)
    {
        cout << "\nThe tree is empty";
        return;
    }
    else
    {
        stack<node *> st;
        // st is the stack where we are going to store element;
        stack<int> out;
        // the element which pop from st we push into out stack and at the end we pop this out by loop

        // inserting first node
        st.push(root);
        while (!st.empty())
        {
            struct node *curr = st.top();
            st.pop();
            out.push(curr->data);

            if (curr->left)
            {
                st.push(curr->left);
            }
            if (curr->right)
            {
                st.push(curr->right);
            }
        }

        // printing the all postorderelement
        while (!out.empty())
        {
            cout << out.top() << "  ";
            out.pop();
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

    cout << "\npostorder traversing tree\n";
    postorder(r);

    cout << "\npostorder traversing tree by using stack\n";
    postOrderByStack(r);
    return 0;
}