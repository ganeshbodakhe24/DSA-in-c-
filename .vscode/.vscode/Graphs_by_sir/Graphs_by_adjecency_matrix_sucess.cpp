#include <iostream>
using namespace std;
int numvirtex;
int numedges;
int M[10][10];
void initiate()
{
    for (int i = 0; i < numvirtex; i++)
    {
        for (int j = 0; j < numvirtex; j++)
        {
            M[i][j] = 0;
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
            if (M[i][j] >= 10)
            {
                cout << "  " << M[i][j];
            }
            else
            {
                cout << "  0" << M[i][j];
            }
        }
        cout << endl;
    }
}

int main()
{

    int ch = 4;
    cout << "\nEnter the numeber of virtex  ";
    cin >> numvirtex;
    cout << "\nEnter the number of Edges  ";
    cin >> numedges;
    cout << "1)DIRECTED GRAPH 2)UNDIRECTED GRAPH 3)DISPLAY GRAPH 4)EXIT";

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
            cout << "\nExited!!!";
            break;
        }
        default:
        {
            cout << "\nWrong Choice!!!";
            break;
        }
        }
    } while (ch != 4);
    return 0;
}