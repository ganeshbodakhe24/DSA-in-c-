#include <iostream>
#include <string.h>
using namespace std;
#define size 7

class hash_table
{
public:
    int key = -1;
    string record = "--";

} hash_table[size];

int hash_function(int key1)
{
    int hash_value = key1 % size;
    return hash_value;
}

void insert()
{
    int key1;
    int i, hash_value;
    string record1;
    cout << "Enter the key \n";
    cin >> key1;
    cout << "Enter the record \n";
    cin >> record1;
    hash_value = hash_function(key1);

    if (hash_table[hash_value].key != -1)
    {
        i = 1;
        for (int i = 1; i <= size; i++)
        {
            if (hash_table[hash_value].key != -1)
            {
                hash_value = hash_function(key1 + i);
            }
            hash_table[hash_value].key = key1;
            hash_table[hash_value].record = record1;
        }
    }
    else
    {
        hash_table[hash_value].key = key1;
        hash_table[hash_value].record = record1;
    }
}

void display()
{
    int i = 0;
    while (i < size)
    {
        if (hash_table[i].key == -1)
        {
            cout << "\n"
                 << "--"
                 << "\t\t";
            cout << hash_table[i].record;
        }
        else
        {
            cout << "\n"
                 << hash_table[i].key << "\t\t";
            cout << hash_table[i].record;
            cout << endl;
        }

        i++;
    }
}
void delete_element()
{
    int element;
    cout << "Enter Key\n";
    cin >> element;
    int i = 0;
    while (i != size)
    {
        if (hash_table[i].key == element)
        {
            hash_table[i].key = -1;
            hash_table[i].record = "--";
            cout << "Your data deleted sucessfully\n";
        }
        i++;
    }
}
int main()
{
    cout << "This  is programe of hash table\n";
    int i = 0;
    int ch = 4;
    cout << " 1) Insert\n 2)display\n 3)delete \n 4)Exit\n";

    do
    {
        cout << "Enter your choice :";
        ch = 4;
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            insert();
            break;
        }
        case 2:
        {
            display();
            break;
        }
        case 3:
        {
            delete_element();
            break;
        }
        case 4:
        {
            cout << "Exit\n";
            break;
        }
        default:
        {
            cout << "\nWrong Choice!!!\n";
        }
        }

    } while (ch != 4);
}