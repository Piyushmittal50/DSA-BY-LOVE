// Stock Buy And Sell
// Time complexity o(n^2)
// space complexity o(1)
#include<bits/stdc++.h>
using namespace std;
int BuySell(int arr[],int n){
    int maxpro = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
               maxpro = max(arr[j] - arr[i],maxpro);
            }
        }
    }
    return maxpro;
}
// Better approach    --O(N)
int maxProfit(vector<int> &arr){
    int maxPro = 0;
    int n = arr.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < arr.size(); i++){
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }

    return maxPro;
}
int main(){
    int arr[] = {7,1,5,3,6,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int ans = BuySell(arr,size);
    cout<<"Maximum profit is : "<<ans<<endl;
} 
