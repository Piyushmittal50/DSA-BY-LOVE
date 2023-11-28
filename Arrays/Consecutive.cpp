// Count Maximum Consecutive One’s in the array
#include<bits/stdc++.h>
using namespace std;
int findMaxConsecutiveOnes(vector<int> &num,int n){
    int con = 0;
    int maxi = 0;
    for(int i=0;i<n;i++){
        if(num[i]==1){
            con++;
        }
        else{
            con = 0;
        }
        maxi = max(maxi,con);
    }
    return maxi;
}
int main(){
   vector<int> nums = {1,1,0,1,1,1};
   int size = sizeof(nums)/sizeof(nums[0]);
   int ans = findMaxConsecutiveOnes(nums,size);
   cout<<"The Maximum Consecutive 1's are : "<<ans<<endl;
   return 0;
}