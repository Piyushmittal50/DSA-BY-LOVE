// Remove Duplicates in-place from Sorted Array
#include<iostream>
#include<vector>
using namespace std;
vector<int> removeSorted(vector<int> arr,int n){
    vector<int> ans;
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[i]!=arr[j]){
            ans.push_back(arr[i]);
            i++;
        }
    }
    return ans;
}
void print(vector<int> arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr = {1,1,2,2,2,3,3};
    int size = 7;
    cout<<"Input is -> "<<endl;
    print(arr,size);
    vector<int> ans = removeSorted(arr,size);
    cout<<"Ans is -> "<<endl;
    print(ans,size);
}