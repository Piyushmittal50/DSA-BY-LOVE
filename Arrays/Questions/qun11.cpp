// Two Sum : Check if a pair with given sum exists in Array
#include<iostream>
#include<vector>
using namespace std;
pair<int,int> twoSum(vector<int> arr,int target){
    int n = arr.size();
     for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==target){
                return {i,j};
            }
        }
     }
     return {-1,-1};
}
void print(vector<int> arr){
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    cout<<"Input is -> "<<endl;
    print(arr);
    pair<int,int> ans = twoSum(arr,target);
    cout<<"answer is -> "<<"{ "<<ans.first<<","<<ans.second<<" }"<<endl; 
}