#include<iostream>
#include<vector>
using namespace std;
vector<int> missingNumber(vector<int> arr,int N){
    vector<int> answer;
    int num = 0;
    for(int i=1;i<arr.size();i++){
     if(arr[num]!=i){
     answer.push_back(i);
     }
     else{
        i++;
     }
     num++;
    }
    return answer;
}
void print(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr = {1,2,4,5};
    int n = 5;
    cout<<"Input is -> "<<endl;
    print(arr);
    vector<int> ans = missingNumber(arr,n);
    print(ans);
}