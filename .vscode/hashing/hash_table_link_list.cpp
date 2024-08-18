#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct node {
    int key;
    string record;
    struct node * next;

};

void hash_table(struct node * ptr){
    int i=0;
    while(i<7){
        
        struct  node * hash_table[i];
        hash_table[i]=(struct node *)malloc (sizeof(struct node));
        hash_table[i]->next=NULL;

        i++;

    }
    

}

int main(){
    struct node * ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
   hash_table(ptr);
   
    cout<<"This is the programme of hash table with link list";
    

    return 0;
}