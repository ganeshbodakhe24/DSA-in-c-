#include <iostream>
using namespace std;
int arr[6]={6,7,1,8,3,5};
void sort(){
    for(int i=1;i<=6;i++){
        for (int j=0;j<6-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main(){
    sort();
    for(int i=0;i<6;i++){
        cout<<" "<<arr[i];
    }
    return 0;
}