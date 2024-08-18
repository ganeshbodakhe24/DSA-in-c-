//prins algo
#include<iostream>
using namespace std;


#define n 6

int numvirtex = 6; // number of edges present in the
int numedges = 9;

int cost = 0; // total cost of minimum spanning tree
// int M[10][10];//adjecency matrix of graph
/*int M[n][n]{
    {0, 3, 0, 0, 1, 4},
    {3, 0, 2, 0, 0, 9},
    {0, 2, 0, 8, 0, 6},
    {0, 0, 8, 0, 2, 0},
    {1, 0, 0, 2, 0, 0},
    {4, 9, 6, 0, 0, 0}

};
int M[n][n]{
    {0, 1, 3, 3, 1},
    {3, 0, 4, 2, 2},
    {0, 2, 0, 0, 4},
    {0, 0, 8, 0, 3},
    {1, 0, 0, 2, 0}
   

};
int M[n][n]{
    {0, 25, 0, 0, 0, 0, 10},
    {0, 0, 15, 9, 0, 0, 0},
    {8, 20, 0, 25, 0, 0, 0},
    {0, 0, 11, 0, 7, 0, 0},
    {2, 0, 0, 12, 0, 50, 55},
    {17, 0, 0, 0, 15, 0, 30},
    {0, 6, 0, 0, 0, 18, 0}

};*/
int M[n][n]{
    {0, 7, 6, 1, 0, 0},
    {3, 0, 8, 0, 0, 0},
    {0, 2, 0, 5, 3, 0},
    {0, 0, 8, 0, 4, 5},
    {1, 0, 0, 2, 0, 2},
    {4, 9, 6, 0, 0, 0}

};
int N[10][10]; // graph generated by kushkal algo

int visited[10]; // node is visited or not

int set[13][3]; // this is the set which is use to store the edges;
// set[a][0]=i; set[a][1]=j; set[a][2]=value of edge;

int chVirtex[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // choice of vertex for DFS
int main(){

    return 0;
}
void chVirtexInitiate()
{
    for (int i = 0; i < 10; i++)
    {
        chVirtex[i] = 0;
    }
}
void initiate()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {

            N[i][j] = 0;
        }
        visited[i] = 0;
    }
}
void prins_algo(int i){
    visited[i];
    for(int j=0;j<numvirtex;j++){
        if(M[i][j]=!0){
            if(visited[j]!=1){
                // store value in array
                N[edind][0] = i;
                N[edind][1] = j;
                N[edind][2] = M[i][j];
                
                edind++;

                if (min > M[i][j])
                {
                    min = M[i][j];
                }
            }
        }
    }
    
}
void DFS(int i)
{
    chVirtex[i] = 1;
    for (int j = 0; j < numvirtex; j++)
    {
        if (N[i][j]!=0)
        {
            if (chVirtex[j] != 1)
            {
                DFS(j);
                chVirtex[j] = 1;
            }
        }
    }
}
void undirectedGraph()
{
    int i, j;
    int edge;
    int m = 0;
    while (m != numedges)
    {
        cout << "\nEnter edge virtex first then second : ";
        cin >> i;
        cout << endl;
        cin >> j;
        cout << "\nEnter edge value : ";
        cin >> edge;
        M[i][j] = edge;
        M[j][i] = edge;
        m++;
    }
}
void directedGraph()
{
    int i, j;
    int edge;
    int m = 0;
    while (m != numedges)
    {
        cout << "\nEnter edge virtex first then second : ";
        cin >> i;
        cout << "  ";
        cin >> j;
        cout << "\nEnter edge value : ";
        cin >> edge;
        M[i][j] = edge;

        m++;
    }
}
void display()
{
    for (int i = 0; i < numvirtex; i++)
    {
        for (int j = 0; j < numvirtex; j++)
        {
            if (N[i][j] >= 10)
            {
                cout << "  " << N[i][j];
            }
            else
            {
                cout << "  0" << N[i][j];
            }
        }
        cout << endl;
    }
}


int main()
{

    int ch = 5;
    cout << "\nEnter the numeber of virtex  ";
    // cin >> numvirtex;
    cout << "\nEnter the number of Edges  ";
    // cin >> numedges;
    cout << "1)DIRECTED GRAPH 2)UNDIRECTED GRAPH 3)DISPLAY GRAPH 4)KUSHKAL ALGO 5)EXIT";

    do
    {
        cout << "\nEnter Choice  ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            initiate();
            directedGraph();
            break;
        }
        case 2:
        {
            initiate();
            undirectedGraph();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            initiate();
            prins_algo();

            cout << "\nthe cost of the Graph is  ";
            cout << cost;
            break;
        }
        case 5:
        {
            cout << "\nExited!!!";
            break;
        }
        default:
        {
            cout << "\nWrong Choice!!!";
            break;
        }
        }
    } while (ch != 5);
    return 0;
}