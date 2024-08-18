// graphs by matrixs

#include <iostream>
using namespace std;
int virtex[10]; // store vertex

int M[10][10]; // graphs edges store by adjecency matrix

int n; // number of vertex
void mkGraph()
{
    int edge; // if edge then "1" else "0"

    char ans; // if edge then "y" else "n"

    cout << "\nNumber of vertex";
    cin >> n;
    cout << "\nEnter value of vertexes\n";
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
            {
                edge = 1;
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

int main()
{
    cout << "Graphs by the matrixs\n";
    mkGraph();
    display();

    return 0;
}