#include<bits/stdc++.h>
using namespace std;

vector<int> find3Sum(vector<int> arr,int n,int target){
    vector<int> ans;
    for (int i = 0; i < n-2;i++){
        int low = i+1;
        int high = n - 1;
        while(low<high){
            int current = arr[i] + arr[low] + arr[high];
            if(current==target){
                ans.push_back(i);
                ans.push_back(low);
                ans.push_back(high);
                break;
            }
            else if(current<target){
                low++;
            }
            else{
                high--;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 13;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<int> index = find3Sum(arr, n, target);
    if(index.size()==0){
        cout<<"No such triplet found"<<endl;
    }
    else{
        cout<<index[0]<<" "<<index[1]<<" "<<index[2]<<endl;
    }
}