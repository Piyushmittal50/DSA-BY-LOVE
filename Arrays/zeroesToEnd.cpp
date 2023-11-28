// Move all Zeros to the end of the array
// Time Complexity O(N)
// Space Complexity O(N)
#include<bits/stdc++.h>
using namespace std;
void printarray(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;      
}
void zeroesToEnd(int arr[],int n){
    int k = 0;
    int i;
    for(i=0;i<n;i++){
    if(arr[i]!=0){
    arr[k] = arr[i];
    k++; 
    }
    }
    while(k<n){
        arr[k] = 0;
        k++;
    }
    printarray(arr,n);
}

int main(){
    int arr[] = { 1,2,0,1,0,4,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Given Array is : "<<endl;
    printarray(arr,size);
    cout<<"Aftee Shifting Zeroes : "<<endl;
    zeroesToEnd(arr,size);
}