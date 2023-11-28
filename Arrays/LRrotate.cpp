// Left Rotate An Array one place
// Time Complexity O(N)
// Space Complexity O(N)

#include<bits/stdc++.h>
using namespace std;

void leftRotate(int arr[],int n){
    int temp;
    temp = arr[0];
    for(int j=1;j<n;j++){
        arr[j-1] = arr[j]; 
    }
    arr[n-1] = temp;
}

void printarray(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"The Given Array is : "<<endl;
    printarray(arr,size);
    leftRotate(arr,size);

    cout<<"After Left Rotate By Ones : "<<endl;

     printarray(arr,size);

}


// Approach Second in O(N) Time Only

#include<bits/stdc++.h>
using namespace std;

void leftRotate(int arr[],int n){
    int temp;
    temp = arr[0];
    for(int i=0;i<n-1;i++){
        arr[i] = arr[i+1]; 
    }
    arr[n-1] = temp;
}

void printarray(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"The Given Array is : "<<endl;
    printarray(arr,size);
    leftRotate(arr,size);

    cout<<"After Left Rotate By Ones : "<<endl;

     printarray(arr,size);

}
