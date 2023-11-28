#include<iostream>
using namespace std;
void DutchNation(int arr[],int m){
   int low = 0;
   int high = m-1;
   while(low<high){
    if(arr[low]==0){
        low++;
    }
    else if(arr[high]==1)
    {
        high--;
    }
    
    else{
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
   }
}
void printarray(int arr[],int n){
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
   }
   cout<<endl;
}
int main(){
    int arr[] = {0, 1, 1, 0, 1, 0};
    int size = sizeof(arr)/sizeof(arr[0]);
    DutchNation(arr,size);
    printarray(arr,size);

}