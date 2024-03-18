// Find the Majority Element that occurs more than N/2 times
#include<bits/stdc++.h>
using namespace std;
int Majority(vector<int> arr){
    sort(arr.begin(),arr.end());

    int cont01 = 0, cont02 = 0,cont03 = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==1){
            cont01++;
        }
        else if (arr[i]==2) cont02++;
        else cont03++;
    }
    int majo = -1;
    if(cont01 > cont02 && cont01 > cont03 ) majo = 1;
    else if (cont02 > cont01 && cont02 > cont03) majo = 2;
    else majo = 3;

    if (cont01 > arr.size() / 2 || cont02 > arr.size() / 2 || cont03 > arr.size() / 2) {
        return majo;
    } else {
        return -1;
    }
}
int MajorityEle(vector<int> arr){
    int n = arr.size();
    map<int,int> mpp;

    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it : mpp){
        if(it.second > (n/2)){
            return it.first;
        }
    }
    return -1;
}
void print(vector<int> arr){
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr = {2,2,1,1,1,2,2,};
    cout<<"Input is -> "<<endl;
    print(arr);
    int ans = Majority(arr);
    cout<<"Ele is -> "<<ans<<endl;
}