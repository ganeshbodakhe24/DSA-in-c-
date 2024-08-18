// graphs by matrixs

#include <iostream>
using namespace std;

#include <stack> //importing the queue

// deffining the queue
stack<int> s;

// int M[10][10];//adjuncy matrix
#define n  7 // no of vertex
int chvirtex[n]={0,0,0,0,0,0,0} ;//check virtex
int M[n][n] = {
    {0, 1, 1, 1, 0, 0, 0 },
    {1, 0, 1, 0, 0, 0, 0 },
    {1, 1, 0, 1, 1, 0, 0 },
    {1, 0, 1, 0, 1, 0, 0 },
    {0, 0, 1, 1, 0, 1, 1 },
    {0, 0, 0, 0, 1, 0, 0 },
    {0, 0, 0, 0, 1, 0, 0 }

};
void  DFS(int value){
    chvirtex[value]=1;
    cout<<value<<"  ";
    for(int j=0;j<n;j++){
        if(M[value][j]==1){
            if(chvirtex[j]!=1){
                chvirtex[j]=1;
                DFS(j);
            }
        }
    }
   
}

void display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << M[i][j] << "  ";
        }
        cout << endl;
    }
}


int main()
{
    cout << "Graphs by the matrixs\n";

    display();
    cout<<"your graphs virtex is like this\n";
    DFS(0);
 

    return 0;
}