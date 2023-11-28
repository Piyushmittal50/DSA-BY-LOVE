#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
int solve(vector<int>& arr,int target){
// base case
if (target == 0) // when ans = 0;
    return 0;
if (target < 0) // for basically when ans = -1;
    return INT_MAX;
// 1 solve
int minCoins = INT_MAX;
for (int i = 0; i < arr.size(); i++){
    // OUTPUT KO UPDATE
  
    int ans = solve(arr, target-arr[i]);
    if (ans != INT_MAX) // jo answer mil raha hai na bho negative mai nhi hona cheyie
        minCoins = min(minCoins, ans + 1);
}
return minCoins;
}
int main(){
    vector<int> arr = {1,2};
    int target = 3;
    int output = 0;
    int ans = solve(arr, target);
    cout << "Minimum number of ans are : " << ans << endl;
}