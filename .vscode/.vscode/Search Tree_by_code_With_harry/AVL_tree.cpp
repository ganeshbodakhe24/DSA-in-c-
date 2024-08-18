#include <iostream>
using namespace std;
class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;
};
int max(int a, int b){
    if (a>b){
        return a;
    }
    else{
        return b;
    }
}
int getHeight(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

Node *createNode(int key)
{
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}
int getBalanceFactor(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

Node *rightRotate(Node *&y)
{
    Node *x = y->left;
    Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(getHeight(y->right), getHeight(y->left));
    x->height = max(getHeight(x->right), getHeight(x->left));
    return x;
}

Node *leftRotate(Node *&x)
{
    Node *y = x->right;
    Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    y->height = max(getHeight(y->right), getHeight(y->left));
    x->height = max(getHeight(x->right), getHeight(x->left));
    return y;
}

Node *insert(Node *node, int key)
{
    if (node == NULL)
    {
        return createNode(key);
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
       // return node;
       
    }
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);

    // left left casse
    if (bf > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    // right right case
    if (bf < -1 && key > node->right->key)
    {
        return  leftRotate(node);
    }
    // left right case
    if (bf > 1 && key > node->left->key)
    {   node->left=leftRotate(node->left);
        return  rightRotate(node);
    }
    // right left case
    if (bf < -1 && key < node->right->key)
    {   node->right=rightRotate(node->right);
         return leftRotate(node);
    }
    return node;
}
void preorder(Node *root)
{
    if (root != NULL)
    {   
        cout << root->key;
        cout << endl;
        preorder(root->left);
       
       preorder(root->right);
    }
}

int main()
{
   Node *root=NULL;
   root=insert(root,1);
   root=insert(root,2);
  
   root=insert(root,4);
   root=insert(root,5);
    root=insert(root,6);
     root=insert(root,3);
   preorder(root);

    return 0;
}