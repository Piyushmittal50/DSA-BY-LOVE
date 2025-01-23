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
// Moore's Voting Algorithm
int findMajorityElement(int arr[], int n){
    // Step 1: Find a candidate for the majority element
    int candidate = -1, count = 0;

    for (int i = 0; i < n; i++){
        if (count == 0){
            candidate = arr[i];
            count = 1;
        }
        else if (arr[i] == candidate){
            count++;
        }
        else{
            count--;
        }
    }

    // Step 2: Verify if the candidate is the majority element
    count = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] == candidate){
            count++;
        }
    }

    return (count > n / 2) ? candidate : -1;
}
int main(){
    int arr[] = {53 ,75 ,56 ,56 ,56 };
    int size = sizeof(arr)/sizeof(arr[0]);
    int ans = Majorityele(arr,size);
    cout<<"hence the Majority element is : "<< ans <<endl;
}