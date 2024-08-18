#include<iostream>
#include<stdlib.h>
using namespace std;
struct queue *f=NULL;
struct queue *r=NULL;
struct queue {
    int data;
    struct queue *next;
};
   

int is_full(){
    struct queue *ptr;
    ptr=f;
    if(ptr=NULL){
        cout<<"\nQueue is full";
        return 1;
    }
    else{
        cout<<"\nQueue is not full";
        return 0;   
    }
}

int is_empty1(){
   
    if(f==NULL){
        cout<<"\nQUEUE IS EMPTY!!";
        return 1;
        }
    else{
        cout<<"\nQUEUE IS NOT EMPTY";
        return 0;
   
    }
}

void enqueue(int val){
   
    struct queue *ptr;
    ptr=(struct queue*)malloc(sizeof(struct queue));
    if(ptr==NULL){
        cout<<"QUEUE IS FULL";
    }
    else{
        ptr->data=val;
        ptr->next=NULL;
       
        if(f==NULL){
            f=r=ptr;
        }
        else{
            r->next=ptr;
            r=ptr;
        }
       
    }
   
}
int main(){
    is_full();
   
    enqueue(5);
    is_full();
    is_empty1();
}
   