#include <iostream>
#include <string.h>
#define size 5
using namespace std;

class Hash_table
{
public:
    int key = -1;
    string record = " --";

} Hash_table[size];

void insert()
{

    int i, hash_value;
    int flag = 1;
    int key;
    string record;

    cout << "\nEnter key : ";
    cin >> key;
    cout << "\nEnter record : ";
    cin >> record;
    hash_value = key % size;
    if (Hash_table[hash_value].key != -1)
    {
        i = 1;
        while (Hash_table[hash_value].key != -1)
        {
            hash_value = (hash_value + 1) % size;
            i++;
            if (i > size)
            {
                cout << "\nThe Hash_table is overflow";
                cout << "\nhash value  " << hash_value;
                flag = 0;
                break;
            }
        }
    }
    if (flag == 1)
    {
        Hash_table[hash_value].key = key;
        Hash_table[hash_value].record = record;
    }
}
void display()
{

    for (int i = 0; i < size; i++)
    {
        cout << " key : " << Hash_table[i].key;
        cout << "    ";
        cout << "record : " << Hash_table[i].record;
        cout << endl;
        cout << endl;
    }
}
void search(int value)
{

    for (int i = 0; i < size; i++)
    {
        if (Hash_table[i].key == value)
        {
            cout << "\nThe value is found at index " << i;
            return;
        }
    }
}
void delete_key(int value)
{

    for (int i = 0; i < size; i++)
    {
        if (Hash_table[i].key == value)
        {
            cout << "\nElement deleted ";
            Hash_table[i].key=-1;
            Hash_table[i].record=" --";
            return;
        }
    }
}


int main()
{
    char choice = 'y';
    int value ;
    cout << "\nWe are inserting in the hash table";
    while (choice != 'n' && choice != 'N')
    {
        insert();
        cout << "\nDo you want to insert more : ";
        cin >> choice;
    }
    display();
    choice ='y';
    while (choice != 'n' && choice != 'N')
    {
        cout<<"\nEnter value : ";
        cin>>value;
        search(value);

        cout<<"\nEnter value to delete : ";
        cin>>value;
        delete_key(value);
        display();

        cout << "\nDo you want to insert more : ";
        cin >> choice;
      
    }
    return 0;
}
