// Left Rotate the Array by One
#include<iostream>
using namespace std;
void leftRotate(int arr[],int n){
     int temp = arr[0];
     int count = 0;
     for(int i=1;i<n;i++){
         arr[count] = arr[i];
         count++;
     }
      arr[n-1] = temp;
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = {1,2,3,4,5};
    int n = 5;
    cout<<"input is -> "<<endl;
    print(arr,n);
    leftRotate(arr,n);
    cout<<"Ans is -> "<<endl;
    print(arr,n);
}