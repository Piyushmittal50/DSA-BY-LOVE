#include<bits/stdc++.h>
using namespace std;
int maxLength(int arr[],int n,int k){
 
   int length = 0;
   for(int i=0;i<n;i++){
   	  int currSum = 0;
   	for(int j=i;j<n;j++){
   		currSum = currSum+arr[j];

   		if(currSum==k){
   			length = max(length,j-i+1);
   		}
   	} 
   }
   return length;
}
int main(){
  int arr[] = { 10, 5, 2, 7, 1, 9};
  int k = 15;
  int n = sizeof(arr)/sizeof(arr[0]);
  int ans = maxLength(arr,n,k);
  cout<<"max length : "<<ans<<endl;
}