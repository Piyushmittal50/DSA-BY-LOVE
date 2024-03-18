// Stock Buy And Sell
#include<iostream>
#include<vector>
using namespace std;
// Brute Force Approach   -- O(N^2)
int maxiProfit(vector<int> arr){
    int maxipro = 0;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]>arr[i]){
                maxipro = max(arr[j]-arr[i],maxipro);
            }
        }
    }
    return maxipro;
}
// Better approach    --O(N)
int maxProfit(vector<int> &arr) {
    int maxPro = 0;
    int n = arr.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }
    
    return maxPro;
}
void print(vector<int> arr){
    for(auto i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr = {7,1,5,3,6,4};
    print(arr);
    cout<<"Maximum Profit is -> "<<maxiProfit(arr)<<endl;
}
