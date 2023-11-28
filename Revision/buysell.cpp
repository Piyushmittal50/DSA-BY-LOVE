// buy in minimum price and sell it at maximum price
// indicies -> minutes
// array element -> buy and sell price
// note -> never sell before buy

#include<bits/stdc++.h>
using namespace std;
int maxprofit(int arr[],int n){
    sort(arr,arr+n);// sort the entire arr
    int buy = arr[0];
    int sell = arr[n-1];
    int profit = sell - buy;
    return profit;
}
int main(){
    int arr[] = {2,100,150,120};
    int size = sizeof(arr)/sizeof(arr[0]);

    int result = maxprofit(arr,size);
    cout<<"Maximum profit is : "<<result<<endl;
}
