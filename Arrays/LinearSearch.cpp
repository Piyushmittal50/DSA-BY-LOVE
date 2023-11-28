#include<iostream>
using namespace std;
int LinearSearch(int arr[],int n,int k){
    int i;
    for(i=0;i<n;i++){
        if(arr[i]==k){
            return i;
        }
    }
    return -1;
}
void printarray(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = {1,2,30,34,23,56,67};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k=55;
    cout<<"Array is : "<<endl;
    printarray(arr,size);
    int ans = LinearSearch(arr,size,k);
    if(ans==-1){
        cout<<"Number is not present in the Array ! "<<endl;
    }
    else{
        cout<<"Number present at "<<""<<ans<<" index"<<endl;
    }

}