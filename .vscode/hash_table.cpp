#include<iostream>
#include<string.h>
using namespace  std;
#define size 7
//without collision resolution 

class hash_table{
     public:
     int   key;
     string record;


}hash_table[size];

int hash_function(int key1){
    int hash_value=key1%size;
    return hash_value;
}

void insert(){
    int key1;
    string record1;
    cout<<"Enter the key \n";
    cin>>key1;
    cout<<"Enter the record \n";
    cin>> record1;
    int hash_value=hash_function( key1);
    hash_table[hash_value].key=key1;
    hash_table[hash_value].record=record1;
}

void display(){
    int  i=0;
    while(i<size){
    cout<<"\n"<<hash_table[i].key<<"\t\t"; 
    cout<<hash_table[i].record;
    cout<<endl;
    i++;
    }
}

int  main(){
    cout<<"This  is programe of hash table\n";
    int i=0;
    int ch;
    cout<<"1) Insert, 2)display\n";
    do{
        cout<<"Enter your choice :";
        cin>>ch;
        switch(ch){
            case 1:{
                insert();
                break;
                }
            case 2:{
                display();
                break;
            }
        }



    }while(i<size);
}