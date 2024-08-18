//graphs by matrixs

#include<iostream>
using namespace std;
int M[10][10];//adjuncy matrix
int n;//no of vertex
void mkGraph(){
    int edge;
    char ans;//if edge then "y" else "n"
    cout<<"\nNumber of vertex";
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<i<<"  and  "<<j<<"  have an edge :  ";
            cin>>ans;
            if(ans=='y'||ans=='Y'){
                edge=1;
            }
            else{
                edge=0;
            }
            M[i][j]=edge;
            cout<<endl;
            M[i][j]=edge;
        }
    }

}
void display(){
     for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                cout<<M[i][j]<<"  ";
        }
        cout<<endl;
     }
    
}
void displayEdgeWithVertex(){
    cout << "\nThe graphs matrix is like this\n";
    for (int i = 0; i < n; i++)
    {
        cout<<i<<" have an edge with :  ";
        for (int j = 0; j < n; j++)
        {
            if(M[i][j]==1){
                cout<< j <<"  ";
            }
        }
        cout << endl;
    }
}

int main(){
    cout<<"Graphs by the matrixs\n";
    mkGraph();
    display();
    displayEdgeWithVertex();
     
    
    return 0;
}