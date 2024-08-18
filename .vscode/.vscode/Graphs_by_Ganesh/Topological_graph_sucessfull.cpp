#include <iostream>
using namespace std;
int numvirtex;
int numedges;
int checkvertex[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
// int indegree[10];
int indegree[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int M[10][10];
/*
int M[4][4] = {
    {0, 1, 0, 0},
    {0, 0, 0, 0},
    {0, 1, 0, 0},
    {1, 0, 1, 0}};


int M[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}};
    */

void clear()
{
    for (int i = 0; i < numvirtex; i++)
    {
        indegree[i] = 0;
    }
}
void initiate()
{
    for (int i = 0; i < numvirtex; i++)
    {
        for (int j = 0; j < numvirtex; j++)
        {
            M[i][j] = 0;
        }
        indegree[i] = 0;
    }
}

void directedGraph()
{
    int i, j;
    int edge = 1;
    int m = 0;
    while (m != numedges)
    {
        cout << "\nEnter edge virtex first then second : ";
        cin >> i;
        cout << "  ";
        cin >> j;
        M[i][j] = edge;

        m++;
    }
}

void findInderee()
{
    for (int i = 0; i < numvirtex; i++)
    {
        int count = 0;
        for (int j = 0; j < numvirtex; j++)
        {
            if (M[j][i] == 1)
            {
                count++;
            }
            indegree[i] = count;
        }
    }
}

void displayIndegree()
{
    for (int i = 0; i < numvirtex; i++)
    {
        cout << i << "  : " << indegree[i] << endl;
    }
}
int topological_graph()
{
    int task = 0;
    while (task < numvirtex)
    {
        task++;
        findInderee();
        for (int i = 0; i < numvirtex; i++)
        {
            if (checkvertex[i] == 0)
            {

                if (indegree[i] == 0)
                {
                    checkvertex[i] = 1;
                   // displayIndegree();
                    //cout << endl;
                    cout << i << endl;//<<endl;

                    for (int j = 0; j < numvirtex; j++)
                    {
                        M[i][j] = 0;
                    }
                }
            }
        }
        clear();
        ;
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

    int ch = 6;
    cout << "\nEnter the numeber of virtex  ";
    cin >> numvirtex;
    cout << "\nEnter the number of Edges  ";
    cin >> numedges;
    cout << "1)DIRECTED GRAPH 2) FIND IN_DEGREE  3)DISPLAY GRAPH 4)CALL TOPOLOGYCAL ALGO 5) INDEGREE DISPLAY 5)EXIT";

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
            cout << "Indegree is made ";
            findInderee();
            break;
        }
        case 3:
        {
            display();

            break;
        }
        case 4:
        {
            cout << "Topologycal algo output :\n";
            topological_graph();
            break;
        }
        case 5:
        {
            cout << "\nThe indegree is like follow : ";
            displayIndegree();
            break;
        }
        case 6:
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
    } while (ch != 6);
    return 0;
}