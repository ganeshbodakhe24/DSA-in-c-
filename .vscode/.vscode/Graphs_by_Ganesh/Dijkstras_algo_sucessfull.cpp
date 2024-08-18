#include <iostream>
using namespace std;
int numvirtex;
int numedges;
// int M[10][10];
/*int M[4][4] = {
    {0, 1, 4, 0},
    {1, 0, 0, 2},
    {4, 0, 0, 5},
    {0, 2, 5, 0}

};
int M[5][5] = {
    {0, 5, 5, 0, 5},
    {5, 0, 0, 3, 0},
    {5, 0, 0, 4,  6},
    {0, 3, 4, 0, 0},
    {5, 0, 6, 0, 0}

};
int M[6][6] = {
    {0, 4, 4, 0, 0, 0},
    {4, 0, 2, 0, 1, 0},
    {4, 2, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 2},
    {0, 1, 0, 0, 0, 4},
    {0, 0, 0, 2, 4, 0}
};*/
int M[9][9]={
    {0,2,0,0,0,7,3,0,0},
    {2,0,4,0,0,0,6,0,0},
    {0,4,0,2,0,0,0,2,0},
    {0,0,2,0,1,0,0,8,0},
    {0,0,0,1,0,6,0,0,2},
    {7,0,0,0,6,0,0,0,0},
    {3,6,0,0,0,0,0,3,1},
    {0,0,2,8,0,0,3,0,4},
    {0,0,0,0,2,0,1,4,0}
};
// to store the value we have to make array
int arr[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int visited[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int minValue(int virtex)
{
    int min = 100;
    for (int i = 0; i < numvirtex; i++)
    {
        if (arr[i] != 0 && arr[i] != -1 && arr[i] < min)
        {   if(visited[i]==0){
             min = arr[i];
        }
           
        }
    }
    for (int i = 0; i < numvirtex; i++)
    {  
        if (arr[i] == min && visited[i]==0)
        {  
            return i;
        }
        
    }
    return -1;
}
void dijkstras_algo(int virtex)
{
    visited[virtex]=1;
    int count = 0;
    for (int j = 0; j < numvirtex; j++)
    {
        if (M[virtex][j] != 0)
        {
            arr[j] = M[virtex][j];
        }
    }
    arr[virtex]=0;

    while (count !=numvirtex)
    {
        count++;
        int i = minValue(virtex); // the minimum virtex is selected
        cout<<i <<" ";
        if(i==-1){break;}
        visited[i]=1;
        for (int j = 0; j < numvirtex; j++)
        {
            if (M[i][j] != 0)
            {
                if (arr[j] != 0 && arr[j] != -1 )
                {
                    if ((arr[i] + M[i][j]) < arr[j])
                    {
                        arr[j] = M[i][j] + arr[i];
                    }
                }else if( arr[j] == -1){
                    arr[j] = M[i][j] + arr[i];
                }
            }
        }
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

    int ch = 5;
    cout << "\nEnter the numeber of virtex  ";
    cin >> numvirtex;
    cout << "\nEnter the number of Edges  ";
    cin >> numedges;
    cout << "1)DIRECTED GRAPH 2)DISPLAY GRAPH  3)Dijekstra's algo 4) display weight 5)EXIT";

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
            /* initiate();
             undirectedGraph();
           */
           display();
            break;
        }
        case 3:
        {
           dijkstras_algo(0);
            break;
        }
        case 4:
        {   cout<<"the value of virtex as like this :\n";
            for(int i=0;i<numvirtex;i++){
                cout<<arr[i]<<"  ";
            }
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