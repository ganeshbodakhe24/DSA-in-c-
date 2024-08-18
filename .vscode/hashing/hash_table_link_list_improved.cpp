#include <iostream>
#include <stdlib.h>
#include <string.h>
#define size 7

using namespace std;
struct node
{
    int key;
    string record;
    struct node *next;
};
struct hash_table
{
    struct hash_table *sub_list = NULL;
    struct hash_table *index;
};



struct hash_table * create_hash_table()
{

    struct hash_table *hash_table0;
    hash_table0 = (struct hash_table *)malloc(sizeof(struct hash_table));
    struct hash_table *hash_table1;
    hash_table1 = (struct hash_table *)malloc(sizeof(struct hash_table));
    struct hash_table *hash_table2;
    hash_table2 = (struct hash_table *)malloc(sizeof(struct hash_table));
    struct hash_table *hash_table3;
    hash_table3 = (struct hash_table *)malloc(sizeof(struct hash_table));
    struct hash_table *hash_table4;
    hash_table4 = (struct hash_table *)malloc(sizeof(struct hash_table));
    struct hash_table *hash_table5;
    hash_table5 = (struct hash_table *)malloc(sizeof(struct hash_table));
    struct hash_table *hash_table6;
    hash_table6 = (struct hash_table *)malloc(sizeof(struct hash_table));
    

    hash_table0->index = hash_table1;
    hash_table1->index = hash_table2;
    hash_table2->index = hash_table3;
    hash_table3->index = hash_table4;
    hash_table4->index = hash_table5;
    hash_table5->index = hash_table6;
    hash_table6->index = NULL;
    
return hash_table0;

}
void create_list(struct hash_table * head){
    struct node ptr1;
    ptr1=(struct node*)malloc(sizeof(struct node));
    struct node ptr2;
    ptr2=(struct node*)malloc(sizeof(struct node));
    struct node ptr3;
    ptr3=(struct node*)malloc(sizeof(struct node));
    
    head->sub_list=ptr1;
     ptr =head->index;


}

int main()
{
    
    cout << "This is the programme of hash table with link list";
    struct hash_table * head;
    head=create_hash_table();
    create_list(head);
   

    return 0;
}