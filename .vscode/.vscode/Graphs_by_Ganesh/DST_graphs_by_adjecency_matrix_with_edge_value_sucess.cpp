#include <iostream>
using namespace std;



int virtex[10]; // store vertex

int M[10][10]; // graphs edges store by adjecency matrix

int chVirtex[10]={0,0,0,0,0,0,0,0,0,0};//choice of vertex

int n; // number of vertex
void mkGraph()
{
    int edge; // if edge then "1" else "0"

    char ans; // if edge then "y" else "n"

    cout << "\nNumber of vertex  : ";
    cin >> n;
    cout << "\nEnter value of vertexes  \n";
    // fill the vertex array
    for (int i = 0; i < n; i++)
    {
        cin >> virtex[i];
    }
    // give edges in matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << virtex[i] << "  and  " << virtex[j] << "  have an edge :  ";
            cin >> ans;
            if (ans == 'y' || ans == 'Y')
            {   cout<<"edge  value";
                cin>>edge;
            }
            else
            {
                edge = 0;
            }
            M[i][j] = edge;
            cout << endl;
            M[i][j] = edge;
        }
    }
}
void display()
{
    cout << "\nThe graphs matrix is like this\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << M[i][j] << "  ";
        }
        cout << endl;
    }
}
// to search index in array for the value
int searchIndex(int value)
{
    for (int m = 0; m < n; m++)
    {
        if (value == virtex[m])
        {
            return m;
        }
    }
}

void DFS(int value)
{ int i;
   cout<<value <<"  ";
   
     i = searchIndex(value);
    chVirtex[i] = 1;
        for (int j = 0; j < n; j++)
        {
            if (M[i][j] != 0)
            {
                if (chVirtex[j] != 1)
                {
                   DFS(virtex[j]);
                   chVirtex[j]=1;
                }
            }
        }
    
}

int main()
{   int virtex;
    cout<<"Start virtes : \n";
    cin>>virtex;
    mkGraph();
    display();
   DFS(virtex );

    return 0;
}
