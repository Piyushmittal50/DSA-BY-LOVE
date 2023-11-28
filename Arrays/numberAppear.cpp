// Find the number that appears once, and the other numbers twice
#include<iostream>
using namespace std;
int numberAppear(int arr[],int n){
   
   for(int i=0;i<n;i++){
     int temp = arr[i];
      int count = 0;
    for(int j=0;j<n;j++){
     if(arr[j]==temp){
      count++;
     }       
    }
    if(count==1){
        return temp;
    }
   }
   return -1;
}
int main(){
    int arr[]  = {2,2,2,4,5,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int ans = numberAppear(arr,size);
    cout<<"The Number Appear 1's is : "<<ans<<endl;
return 0;
}