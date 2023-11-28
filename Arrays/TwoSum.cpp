// Using two loops ( brute force approach)
// Time complexity = O(N^2)
// Space complexity = O(1)
#include<bits/stdc++.h>
using namespace std;
 vector<int> Two_Sum(int arr[],int n,int target){
     vector<int> number;
     for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==target){
              number.push_back(i);
              number.push_back(j);
            }
        }
     }
     return number;
 }
int main(){
    int target = 19;
    int arr[] = {2,6,5,8,11};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int> result = Two_Sum(arr,size,target);
    cout<< "The Answer is : " <<result[0]<<","<<result[1]<<endl;
}

// using two pointer
// Time complexity = O()
#include<bits/stdc++.h>
string twosum(vector<int> &arr,int n,int target){
    sort(arr.begin(),arr.end());
    int start = arr[0];
    int end = arr[n-1];
    while(start<end){
        int sum  = arr[start]+arr[end];
        if(sum==target){
            return "yes";
        }
        else if(sum<target){
            end--;
        }
        else{
            start++;
        }
    }
    return "NO";
}