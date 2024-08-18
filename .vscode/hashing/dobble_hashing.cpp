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

int hash_function1(int key1)
{
    int hash_value = key1 % size;
    return hash_value;
}

int hash_function2(int key1)
{
    int hash_value = key1 % 5;
    return hash_value;
}

void insert()
{
    int key1, hash_value1, hash_value2, hash_value3;
    string record1;
    cout << "Enter the key \n";
    cin >> key1;
    cout << "Enter the record \n";
    cin >> record1;

    hash_value1 = hash_function1(key1);
    hash_value3 = hash_value1;

    if ((hash_table[hash_value1].key)!= -1)
    {
        int i = 1;
        while (hash_table[hash_value3].key!= -1)
        {
            hash_value2 = hash_function2(key1);
            hash_value3 = (hash_value1 + (i * hash_value2))% size;
            i++;
        }
        
        hash_table[hash_value3].key = key1;
        hash_table[hash_value3].record = record1;
    }
    else{

    hash_table[hash_value1].key = key1;
    hash_table[hash_value1].record = record1;
    }
}

void display()
{
    int i = 0;
    while (i < size)
    {   
        if(hash_table[i].key==-1){
            cout<<"\n"
                <<"--"<< "\t\t";
            cout<<hash_table[i].record;
            i++;
        }
        else{
        cout << "\n"
             << hash_table[i].key << "\t\t";
        cout << hash_table[i].record;
        cout << endl;
        i++;
        }
    }
}

int main()
{
    cout << "This  is programe of hash table\n";
    int i = 0;
    int ch;
    cout << "1) Insert, 2)display\n";
    do
    {
        cout << "Enter your choice :";
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
        default:
        cout<<"wrong choice\n";
        }

    } while (i < size);
}