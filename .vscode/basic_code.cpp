#include<iostream>
using namespace std;

int main(){
    int a=40;
    int & b=a;
    cout<<&b;
    cout<<endl;
    cout<<&a;
    cout<<endl;
    cout<<b;
    cout<<endl;
    int c=a++;
    cout <<c;
    return 0;
}