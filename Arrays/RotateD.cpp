// Rotate array by K elements
#include<bits/stdc++.h>
using namespace std;
void reverse(int arr[],int start,int end){
    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
// Function to Rotate k elements to right
void rotatetoRight(int arr[],int n,int k){
    // Revesal Algo
    // first reverse n-k element
    reverse(arr,0,n-k-1);
    // now reverse k element
    reverse(arr,n-k,n-1);
    // now reverse whole array
    reverse(arr,0,n-1);
}
void rotatetoLeft(int arr[],int n,int k){
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    reverse(arr,0,n-1);
}
void printarray(int arr[],int size){
    int i;
    for(i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    cout<<"Array is : "<<endl;
    printarray(arr,n);
    rotatetoRight(arr,n,k);
    cout<<"After the RightRotation : "<<endl;
    printarray(arr,n);
    rotatetoLeft(arr,n,k);
    cout<<"After the LeftRotation : "<<endl;
    printarray(arr,n);
}