#include<bits/stdc++.h>
using namespace std;
int Majorityele(int arr[],int n){
    int i=0;
    int j=0;
 
    for(i=0;i<n;i++){
     int count = 0;
        for(j=0;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
         if(count>n/2){
        return arr[i];
    }
    }
   
    return -1;
}
int main(){
    int arr[] = {53 ,75 ,56 ,56 ,56 };
    int size = sizeof(arr)/sizeof(arr[0]);
    int ans = Majorityele(arr,size);
    cout<<"hence the Majority element is : "<< ans <<endl;
}