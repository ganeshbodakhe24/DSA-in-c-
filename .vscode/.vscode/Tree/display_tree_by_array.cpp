#include <iostream>
using namespace std;
#include <math.h>
#include <string.h>
#define size 100

string binary_tree[size];

void insert_elements(int height)
{

    int power = (int)(pow(2, height));
    int tot_node = power - 1;
    cout << "root node :" << endl;
    cin >> binary_tree[0];

    for (int i = 1; i < tot_node; i += 2)
    {
        int parent_node = (i - 1) / 2;
        cout << "Enter " << binary_tree[parent_node] << "  Parent's left node  : " << endl;
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

        
        // j is the node count in single level
           

        int power = (int)(pow(2, i));
        for (int j = 0; j < power; j++)
        {   int m=i;
            while(m<height){
                
                cout<<"\t\t";
                m++;
            }
            cout  << binary_tree[index];
            index++;
        }
        cout << "\t   The level : " << i;
        cout << "\n";
    }
}

int main()
{
    int choice, height;
    cout << "This is the representation of the binary tree with array" << endl;

    while (choice != 6)
    {
        cout << "1) Insert nodes\n2) Display\n3) Find left child\n4) Find right child\n5) Find parents\n6) Exit\n"
             << endl;
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
            cout << "find left child";
            break;
        }
        case 4:
        {
            cout << "find right child";
            break;
        }
        case 5:
        {
            cout << "find parents node";
            break;
        }
        case 6:
        {
            cout << "Exited";
            break;
        }
        default:
        {
            cout << "You Entered wrond chice \n";
        }
        }
    }
    return 0;
}