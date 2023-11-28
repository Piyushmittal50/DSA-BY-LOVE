#include<iostream>

using namespace std;
void swapfunction(int &start,int &end){
    int temp;
    temp = start;
    start= end;
    end= temp;
}
void bubble(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
              if(arr[j]>arr[j+1]){
                swapfunction(arr[j],arr[j+1]);
              }
        }
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){

        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = {23,16,46,12,14};
    int size = sizeof(arr)/sizeof(arr[0]);

    bubble(arr,size);
    cout<<"after sorting : "<<endl;
    print(arr,size);
}