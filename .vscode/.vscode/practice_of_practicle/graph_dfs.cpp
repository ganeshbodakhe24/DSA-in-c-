//graph in dfs
#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

int M[10][10];
int num_edge;
int num_vertex;
int visited[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void display()
{
    for (int i = 1; i <= num_vertex; i++)
    {
        for (int j = 1; j <= num_vertex; j++)
        {
            cout << M[i][j];
            cout << " ";
        }
        cout << endl;
    }
}
void DFS(int value)
{
    int i = value;
    visited[i]=1;
    cout<<value;
    for (int j = 1; j <= num_vertex; j++)
    {
        if (M[i][j] == 1)
        {
            if (visited[j] != 1)
            {
                DFS(j);
                visited[j] = 1;
            }
        }
    }
}

void mkgraph()
{
    int count = 0;
    while (count != num_edge)
    {
        int i, j;
        cout << "Enter vertex 1 ";
        cin >> i;
        cout << endl;
        cout << "Enter vertex 2 ";
        cin >> j;
        cout << endl;
        int edge_value = 1;

        M[i][j] = edge_value;
        M[j][i] = edge_value;
        count++;
    }
}

int main()
{
    cout << "Enter number of vertexes in graph\n";
    cin >> num_vertex;
    cout << "Enter number of edges in graph\n";
    cin >> num_edge;
    mkgraph();
    display();
    cout << "the DFS of the graph is ";
    DFS(1);
    return 0;
}