#include <iostream>
using namespace std;
int numvirtex;
int numedges;
int M[10][10];
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
};
int M[9][9] = {
    {0, 2, 0, 0, 0, 7, 3, 0, 0},
    {2, 0, 4, 0, 0, 0, 6, 0, 0},
    {0, 4, 0, 2, 0, 0, 0, 2, 0},
    {0, 0, 2, 0, 1, 0, 0, 8, 0},
    {0, 0, 0, 1, 0, 6, 0, 0, 2},
    {7, 0, 0, 0, 6, 0, 0, 0, 0},
    {3, 6, 0, 0, 0, 0, 0, 3, 1},
    {0, 0, 2, 8, 0, 0, 3, 0, 4},
    {0, 0, 0, 0, 2, 0, 1, 4, 0}};
    */
// to store the value we have to make array

int arr[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1}; // array where weight of virtex is store value
int visited[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};       // edge is visited or not

int edge_comes_from[10] = {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // it show from where edge is comes

char store_virtex[10];//use to store virtex name 

// it gives virtex postion of minimum value but virtex should not visited
int minValue(int virtex)
{ // initial minimum value of the virtex;
    int min = 1000;
    // travelling in arr to search minimum value but the virtex should not be visited
    for (int i = 0; i < numvirtex; i++)
    {
        // virtex should not visited and value present at vertex should not be zero and -1
        if (arr[i] != 0 && arr[i] != -1 && arr[i] < min)
        {
            if (visited[i] == 0)
            {
                min = arr[i];
            }
        }
    }
    // to finding virtex poisiton in arr for minimum value
    for (int i = 0; i < numvirtex; i++)
    {
        if (arr[i] == min && visited[i] == 0)
        {
            return i;
        }
    }
    // if we didnt find the virtex not visited then return -1 to terminate the programme
    return -1;
}
// starting of djikstras_algo
void dijkstras_algo(int virtex)
{ // starting the algo with virtex 0
    visited[virtex] = 1;
    int count = 0;
    // insert the 0 virtex weight in the arrr
    for (int j = 0; j < numvirtex; j++)
    {
        if (M[virtex][j] != 0)
        {
            arr[j] = M[virtex][j];
        }
    }
    arr[virtex] = 0;
    // arr=0 this indicate the starting point is 0 th vertex

    while (count != numvirtex)
    {
        count++;
        int i = minValue(virtex); // the minimum virtex is selected
        cout << i << " ";
        // if you get -1 then terminate the loop
        if (i == -1)
        {
            break;
        }
        visited[i] = 1; // mark the i virtex as visited
        // loop for adding weight if previous weight is greater than the present weight
        for (int j = 0; j < numvirtex; j++)
        {
            if (M[i][j] != 0)
            {
                if (arr[j] != 0 && arr[j] != -1)
                {
                    if ((arr[i] + M[i][j]) < arr[j])
                    {
                        edge_comes_from[j] = i;
                        arr[j] = M[i][j] + arr[i];
                    }
                } // if the there no value in arr then simply add the weight
                else if (arr[j] == -1)
                {
                    edge_comes_from[j] = i;
                    arr[j] = M[i][j] + arr[i];
                }
            }
        }
    }
}
// to initiate the array
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
// undirected graph
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

// directed graph
void directedGraph()
{
    char i, j;
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
// to display the graph
void display()
{   
    for (int i = 0; i < numvirtex; i++)

    {   cout<<store_virtex[i];
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
void display_weight()
{
    cout << "VERTEX    EDGE COME FROM    WEIGHT\n";

    for (int i = 0; i < numvirtex; i++)

    {
        if (edge_comes_from[i] == -1)
        {

            cout << "  " << i << "          "<< "Source"<< "           " << arr[i] << endl;
            continue;
        }
        cout << "  " << i << "             " << edge_comes_from[i] << "             " << arr[i] << endl;
    }
}
int main()
{

    int ch = 5;
    cout << "\nEnter the numeber of virtex  ";
    cin >> numvirtex;
    
    cout << "\nEnter the number of Edges  ";
    cin >> numedges;
    cout << "1)UNDIRECTED GRAPH 2)DISPLAY GRAPH  3)DIJKSTRA'S ALGORITHM 4) DISPLAY WEIGHT 5)EXIT";

    do
    {
        cout << "\nEnter Choice  ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            initiate();
            undirectedGraph();
            break;
        }
        case 2:
        {

            display();
            break;
        }
        case 3:
        {
            dijkstras_algo(0);
            break;
        }
        case 4:
        {
            cout << "the value of virtex as like this :\n\n";
            display_weight();
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