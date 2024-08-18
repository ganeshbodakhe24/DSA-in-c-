#include <iostream>
#include <stdio.h>
using namespace std;
#define INFINITY 9999
#define max 10
int G[max][max];

void dijkstra(int G[max][max], int n, int startnode);
int numvertex;
int numedges;

void initiate()
{
    for (int i = 0;i<numvertex;i++){
        for(int j=0;j<numvertex;j++){
            G[i][j]=0;
        }
    }
}
void makegraph()
{
    int i, j;
    int m=0;
    int edgeValue;
    while(m!=numedges){
    cout << "\nEnter first virtex of edge : ";
    cin >> i;
    cout << "\nEnter second virtex of edge :";

    cin >> j;
    cout << "\nEnter value of edge : ";
    cin >> edgeValue;
    G[i][j] = edgeValue;
    G[j][i]=edgeValue;
   
    m++;
    }
}
void display(){
    for(int i=0; i<numvertex;i++){
        for(int j=0;j<numvertex;j++){
                cout<<G[i][j];
                cout<<"  ";
        }
        cout<<endl;
    }
}
int main()
{

    cout << "\nEnter is number of vertex  : ";
    cin >> numvertex;
    cout << "\nEnter number of edges  : ";
    cin >> numedges;
    initiate();
    makegraph();
    display();

    int n = numvertex;
    int u = 0;
    dijkstra(G, n, u);
    return 0;
}
void dijkstra(int G[max][max], int n, int startnode)
{
    int cost[max][max], distance[max], pred[max];
    int visited[max], count, mindistance, nextnode, i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
    for (i = 0; i < n; i++)
    {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;
    while (count < n - 1)
    {
        mindistance = INFINITY;
        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }
    for (i = 0; i < n; i++)
        if (i != startnode)
        {
            cout << "\nDistance of node" << i << "=" << distance[i];
            cout << "\nPath=" << i;
            j = i;
            do
            {
                j = pred[j];
                cout << "<-" << j;
            } while (j != startnode);
        }
}