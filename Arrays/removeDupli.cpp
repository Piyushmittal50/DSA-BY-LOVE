// Remove Duplicates in-place from Sorted Array
// By Applying Two Pointer Approach
// Time Complexity O(N)
#include<bits/stdc++.h>
using namespace std;
void printarray(int arr[],int size){
    int i;
    for(i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void removeDuplicate(int arr[],int size){
   int i=0;
   for(int j=0;j<size;j++){
    if(arr[j]!=arr[j+1]){
        arr[i]=arr[j];
        i++;
    }
   }
   cout<<"Array after removing duplicates is : "<<endl;
   printarray(arr,i);
}


int main(){
    int arr[] = {1,1,2,2,2,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"The Given Array is : "<<endl;
    printarray(arr,n);
    cout<<endl;
    removeDuplicate(arr,n);

}