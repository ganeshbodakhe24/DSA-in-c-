#include <iostream>
#include <string.h>
using namespace std;
#define size 7
#define n 5

class hash_table
{
public:
    int key = -1;
    string record = "--";

} hash_table[size];

void insert()
{
    int key1, hash_value;
    string record1;
    cout << "Enter the key \n";
    cin >> key1;
    cout << "Enter the record \n";
    cin >> record1;
    int i = 0;

    hash_value = key1 % size;
    while (hash_table[hash_value].key != -1)
    {
        hash_value = ((key1 % size) + (i * (key1 % n))) % size;
        i++;
    }
    hash_table[hash_value].key = key1;
    hash_table[hash_value].record = record1;
}

void display()
{
    int i = 0;
    cout<<"Index"<<"\t\t"<<"key"<<"\t\t"<<"Value";
    while (i < size)
    {
        if (hash_table[i].key == -1)
        {
            cout << "\n"
                 <<i
                 << "\t\t"
                 << "--"
                 << "\t\t";
            cout << hash_table[i].record;
        }
        else
        {
            cout << "\n"
                <<i
                 << "\t\t"
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
        cout << "\nEnter your choice :";
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