#include<bits/stdc++.h>
using namespace std;
// app 1
int subarray(int arr[],int n){
    int maxi = INT_MIN;
    int currSum = 0;
    for(int i=0;i<n;i++){
        currSum = currSum+arr[i];
        
        if(currSum>maxi){
            maxi = currSum;
        }
        if(currSum<0){
            currSum = 0;
        }
    }
    return maxi;
}
// app 2
int sub(int arr[],int n,int k){
    int maxi = INT_MIN;
    int currSum = 0;
    for(int i=0;i<k;i++){
        currSum = currSum+arr[i];
    }
    int window_sum = currSum;
    for(int i=k;i<n;i++){
        window_sum = window_sum+arr[i]-arr[i-k];
        maxi = max(window_sum,maxi);
    }
    return maxi;
}
int main(){
    int arr[] = {-1,4,7,2};
    int n = 4;
    int ans = subarray(arr,n);
    cout<<"ans is : "<<ans<<endl;
}
