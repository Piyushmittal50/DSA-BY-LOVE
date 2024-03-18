// Sort an array of 0s, 1s and 2s
#include<iostream>
#include<vector>
using namespace std;
vector<int> sortArray(vector<int> arr){
    int con0 = 0, con1 = 0, con2 = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0) con0++;
        else if(arr[i]==1) con1++;
        else con2++;
    }
    for(int i=0;i<con0;i++){
        arr[i] = 0;
    }
    for(int i=con0;i<con0+con1;i++){
        arr[i] = 1;
    }
    for(int i=con0+con1;i<arr.size();i++){
        arr[i] = 2;
    }
   return arr;
}
void print(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    cout<<"Input is -> "<<endl;
    print(arr);
    vector<int> ans = sortArray(arr);
    print(ans);
}