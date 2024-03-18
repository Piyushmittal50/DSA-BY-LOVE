
#include<iostream>
#include<vector>
using namespace std;
vector<int> movesToZeroes(vector<int> arr,int n){
      vector<int> a;

      for(int i=0;i<n;i++){
        if(arr[i]!=0){
        a.push_back(arr[i]);
        }
      }

      int rest = n - a.size();
      while(rest--){
        a.push_back(0);
      }
      return a;
}
vector<int> optimized(vector<int> arr,int n){
    int count = 0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            arr[count] = arr[i];
            count++;
        }
    }
    // Fill the remaining positions with zeros
    while (count < n) {
        arr[count] = 0;
        count++;
    }
    return arr;
}
void print(vector<int> arr,int n){
    for(auto i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {1,0,3,2,0,0,1,4};
    int size = arr.size();
    cout<<"Input is -> "<<endl;
    print(arr,size);
    vector<int> ans = movesToZeroes(arr,size);
    cout<<"The ans is -> "<<endl;
    print(ans,size);
    cout<<"Optimized ans is -> "<<endl;
    vector<int> ans01 = optimized(arr,size);
    print(ans01,size);
}