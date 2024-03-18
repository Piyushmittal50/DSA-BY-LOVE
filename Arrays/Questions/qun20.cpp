// Kadane’s Algorithm : Maximum Subarray Sum in an Array
#include<iostream>
using namespace std;
int maxSum(int arr[],int n){
   int sum = 0;
   int maxi = arr[0];
   for(int i=0;i<n;i++){
    sum = sum + arr[i];
    if(sum > maxi){
        maxi = sum;
    }
    if(sum < 0) sum = 0;
   }
   return maxi;
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Input is -> "<<endl;
    print(arr,size);
    int ans = maxSum(arr,size);
    cout<<"Max sub array sum is : "<<ans<<endl;
}
  
