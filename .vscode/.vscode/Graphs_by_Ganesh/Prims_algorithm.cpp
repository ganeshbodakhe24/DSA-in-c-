#include <iostream>
using namespace std;
#define n 7
// matrix
int M[n][n]{
    {0, 0, 8, 0, 2, 17, 0},
    {0, 0, 20, 0, 0, 0, 6},
    {8, 20, 0, 11, 0, 0, 0},
    {0, 0, 11, 0, 12, 0, 0},
    {2, 0, 0, 12, 0, 15, 0},
    {17, 0, 0, 0, 15, 0, 18},
    {0, 6, 0, 0, 0, 18, 0}

};

int visited[n] = {0, 0, 0, 0, 0, 0, 0}; // give edge is visited or not
int virtex[n] = {0, 0, 0, 0, 0, 0, 0};  // give set of visited nodes
// int edgesvalue[50];//store edges values which visited by pointer
int edind = 0; // it gives index of edgevalue array index
int N[40][3];  // first i, second j, third value,
int totalcost = 0;

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
    // display the sequence of node visited
    cout << "\nthe virtex order\n";
    for (int j = 0; j < n; j++)
    {
        cout << virtex[j] << "  ";
    }
}
// display the sequence at which virtex visited by prims algorithm
void dis_seq_vir()
{
    for (int count = 1; count < 8; count++)
    {
        for (int i = 0; i < n; i++)
        {
            if (virtex[i] == count)
            {
                cout << i << "  ";
            }
        }
    }
}

void prims(int i)
{
    int flag = 1;
    int static count = 1; // this count to count edge value visited sequence
    int indexnum;         // give mininum value index position
    int min = 10000;      // give minimum value of edge
    if(visited[i]=1){virtex[i] = count;
    count++;}
    visited[i] = 1;
    
    
    for (int j = 0; j < n; j++)
    { // j
        if (M[i][j] != 0)
        {
            if (visited[j] != 1)
            { // store value in array
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

   for (int m = 0; m < edind; m++)
    {

        if (min > N[m][2] && N[m][2] != 0)
        {
            min = N[m][2];
            cout << min << " |";
            N[m][2] = 0;
            totalcost = totalcost + min;
            i = N[m][0];
            int j = N[m][1];

            visited[j] = 1;
            prims(j);
            flag = 0;
        }
    }
    // to give min value index position
    if (flag == 1)
    {
        for (int j = 0; j < n; j++)
        {
            if (min == M[i][j])
            {
                cout << min << "  ";
                for (int m = 0; m < edind; m++)
                {
                       if(min == N[m][2]) { N[m][2] = 0;}
                        
                    
                }

                totalcost = totalcost + min;
                visited[j] = 1;
                prims(j);
            }
        }
    }
}
int main()
{
    // display();
    prims(0);
    display();
    cout << "\ndisplay virstex by sequence of visit\n";
    dis_seq_vir();
    cout << " \n The total cost of minimum spanning tree is this :  ";
    cout << totalcost;

    return 0;
}
