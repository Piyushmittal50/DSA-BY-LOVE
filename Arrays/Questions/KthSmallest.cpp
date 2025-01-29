#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int Kthsmall(vector<int> arr,int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto it:arr){
        pq.push(it);
    }
    // remove k-1
    int i = 0;
    while(i<k-1){
        pq.pop();
        i++;
    }
    return pq.top();
}
int main(){
    vector<int> arr = {1, 2, 6, 4, 5, 3};
    int ans = Kthsmall(arr, 2);
    cout << "K th smallest element is : " << ans << endl;
}