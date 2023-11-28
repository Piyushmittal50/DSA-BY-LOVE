// Find the missing number in an array
#include<bits/stdc++.h>
using namespace std;
int missingNumber(int arr[],int n){
   
    // outer loop from 1 to n
    for(int i=1;i<=n;i++){
         int flag=0;
        for(int j=0;j<n-1;j++){
           if(arr[j]==i){
           flag=1;
           break;
           }
        }
        if(flag==0)
        return i;
    }
    return -1;
}
int main(){
 int arr[] = {1,2,4,5};
 int size = sizeof(arr)/sizeof(arr[0]);
 int ans  = missingNumber(arr,size);
 cout<<"The Missing Number is : "<<ans<<endl;
}

// Better Approach ( Using Hashing )
#include<bits/stdc++.h>
using namespace std;
int missingNumber(vector<int>&a,int n){
    int hash[n+1]={0};
    // storing the frequencies
    for(int i=0;i<n-1;i++)
    hash[a[i]]++;
    // checking the freqencies for numbers 1 to n
    for(int i=1;i<=n;i++){
        if((hash[i])==0){
            return i;
        }
    }
    return -1;
}
int main(){
    vector<int> a = {1,2,4,5};
    int size = sizeof(a)/sizeof(a[0]);
    int ans = missingNumber(a,size);
    cout<<"The Missing Number is : "<<ans<<endl;
    return 0;
}