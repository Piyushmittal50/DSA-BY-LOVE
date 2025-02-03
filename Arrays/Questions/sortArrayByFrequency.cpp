#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool sortCustom(pair<int,int> &first,pair<int,int> &second){
    if(first.second==second.second){
        return first.first < second.first;
    }
    return first.second > second.second;
}

vector<int> sortArray(vector<int> arr){
    unordered_map<int, int> mp;
    for(auto it : arr){
        mp[it]++;
    }
    // sort in decreasing order
    vector<pair<int, int>> pq;
    for(auto it:mp){
        pq.push_back({it.first,it.second});
    }
    // it.first -> number
    // it.second -> occur
    sort(pq.begin(), pq.end(),sortCustom);

    vector<int> sorted;
    for (int i = 0; i < pq.size();i++){
        pair<int, int> temp = pq[i];
        int j = 0;
        while(temp.second>j){
            sorted.push_back(temp.first);
            j++;
        }
    }
    return sorted;
}

int main(){
    vector<int> arr = {1, 2, 3, 2, 4, 3, 1, 2};
    vector<int> ans = sortArray(arr);
    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
}