#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
#define size 30

string binary_tree[size];

void insert_elements(int height)
{
    // finding total number of nodes in height
    int power = (int)(pow(2, height));
    int tot_node = power - 1;

    cout << "root node :" << endl;
    cin >> binary_tree[0];

    // Entering value of all nodes
    for (int i = 1; i < tot_node; i += 2)
    {
        int parent_node = (i - 1) / 2;
        cout << "Enter (" << binary_tree[parent_node] << ")  Parent's left node  : " << endl;
        cin >> binary_tree[i];
        cout << "Enter  ( " << binary_tree[parent_node] << " ) Parent's Right node  : " << endl;
        cin >> binary_tree[i + 1];
    }
}

void display(int height)
{
    cout << "Your binary tree :\n";

    // i is the level
    int index = 0;
    for (int i = 0; i < height; i++)
    {

        cout << endl;

        // j is the node count in single level

        int power = (int)(pow(2, i));
        for (int j = 0; j < power; j++)
        {
            int m = i;
            while (m < height)
            {

                cout << "\t\t";
                m++;
            }
            cout << "\t" << binary_tree[index];
            index++;
        }
        cout << "\t The level : " << i;
        cout << "\n";
    }
}

void Find_left_child(int height)
{
    string parent;
    int index = -1;

    cout << "Enter the Parent node\n";
    cin >> parent;

    // find total number of nodes
    int power = (int)(pow(2, height));
    int tot_node = power - 1;

    // find total number of nodes in (height-1)
    int level_power = (int)(pow(2, height - 1));
    int tot_node_of_level = level_power - 1;

    // finding index where the node is present
    for (int i = 0; i < tot_node; i++)
    {
        if (parent == binary_tree[i])
        {
            index = i;
        }
    }
    // element not found
    if (index == -1)
    {
        cout << "Node not found\n";
        return;
    }

    // give left child
    if (index >= tot_node_of_level)
    {
        cout << "Your inlput node is child node\n";
    }
    else
    {
        cout << "Left child :  " << binary_tree[(2 * index) + 1] << endl;
    }
}

void Find_right_child(int height)
{
    string parent;
    int index = -1;
    cout << "Enter the Parent node\n";
    cin >> parent;

    // find total number of nodes
    int power = (int)(pow(2, height));
    int tot_node = power - 1;

    // find the number of nodes present in (height -1)
    int level_power = (int)(pow(2, height - 1));
    int tot_node_of_level = level_power - 1;

    // finding index where the node is present
    for (int i = 0; i < tot_node; i++)
    {
        if (parent == binary_tree[i])
        {
            index = i;
        }
    }
    // element not found
    if (index == -1)
    {
        cout << "Node not found\n";
        return;
    }

    // finding right child node
    if (index >= tot_node_of_level)
    {
        cout << "Your inlput node is child node\n";
    }
    else
    {
        cout << "Right child :  " << binary_tree[(2 * index) + 2] << endl;
    }
}

void find_parent(int height)
{
    string child;
    int index = -1;
    cout << "Enter child \n";
    cin >> child;

    // find index where input  child
    int power = (int)(pow(2, height));
    int tot_node = power - 1;

    for (int i = 0; i < tot_node; i++)
    {
        if (child == binary_tree[i])
        {
            index = i;
        }
    }
    // element not found
    if (index == -1)
    {
        cout << "Node not found\n";
        return;
    }

    // printing parent  of child
    if (index == 0)
    {
        cout << "The input node is Root node\n";
    }
    else
    {
        cout << "Parent is :  " << binary_tree[(int)(index - 1) / 2] << endl;
    }
}
int main()
{
    int choice, height;
    cout << "This is the representation of the complete binary tree with array" << endl;

    while (choice != 6)
    {
        cout << "\n********************************* \n";
        cout << "1) Insert nodes\n2) Display\n3) Find left child\n4) Find right child\n5) Find parents\n6) Exit\n"
             << endl;
        cout << "Enter choice : \n";
        choice = 6;
       
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter height of tree" << endl;
            cin >> height;
            insert_elements(height);
            break;
        }
        case 2:
        {

            display(height);
            break;
        }
        case 3:
        {

            Find_left_child(height);
            break;
        }
        case 4:
        {
            Find_right_child(height);
            break;
        }
        case 5:
        {
            find_parent(height);
            break;
        }
        case 6:
        {
            cout << "Exited";
            break;
        }
        default:
        {
            cout << "You Entered wrong choice \n";
        }
        }
    }
    return 0;
}