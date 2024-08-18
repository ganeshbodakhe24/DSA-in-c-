// graphs by matrixs

#include <iostream>
using namespace std;

#include <queue> //importing the queue

// deffining the queue
queue<int> q;

// int M[10][10];//adjuncy matrix
int n = 4; // no of vertex

int M[4][4] = {
    {0, 1, 0, 0},
    {1, 0, 0, 1},
    {0, 0, 0, 1},
    {0, 1, 1, 0}

};
void  BFS(){
    int chvirtex[n] ;//check virtex
    int value; 
    for(int i=0;i<n;i++){
        chvirtex[i]=0;
    }
    q.push(0);
    chvirtex[0]=1;
    while(q.empty()!=1){
      
       value=q.front();
       cout<<value<<"  ";
        q.pop();
        
        for(int j=0;j<n;j++){
            if(M[value][j]==1){
                if(chvirtex[j]!=1){
                    q.push(j);
                    chvirtex[j]=1;

                }
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
    BFS();
 

    return 0;
}