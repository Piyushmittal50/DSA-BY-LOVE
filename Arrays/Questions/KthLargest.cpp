#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int findKth(vector<int> arr,int k){
    priority_queue<int> pq;
    for(auto it: arr){
        pq.push(it);
    }
    // now remove karege
    int i = 0;
    while(i<k-1){
        pq.pop();
        i++;
    }
    return pq.top();
}

int main(){
    vector<int> arr = {1, 2, 6, 4, 5, 3,10,15,7};
    int ans = findKth(arr, 3);
    cout << "K th largest element is : "<< ans << endl;
}