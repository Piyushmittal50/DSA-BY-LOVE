#include<bits/stdc++.h>
using namespace std;

pair<int,int> twosum(vector<int> arr, int target){
    unordered_map<int, int> number;
    for (int i = 0; i < arr.size(); i++)
    {
        int num = arr[i];
        int temp = target - num;
        if (number.find(temp) != number.end()){
            return {number[temp], i};
        }
        number[temp] = i;
    }
    return {-1, -1};
}
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
// using two pointer
// Time complexity = O(n)
string twosum(vector<int> &arr, int n, int target){
    sort(arr.begin(), arr.end());
    int start = arr[0];
    int end = arr[n - 1];
    while (start < end)
    {
        int sum = arr[start] + arr[end];
        if (sum == target)
        {
            return "yes";
        }
        else if (sum < target)
        {
            end--;
        }
        else
        {
            start++;
        }
    }
    return "NO";
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