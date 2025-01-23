// Leaders in an Array
#include<iostream>
#include<vector>
using namespace std;
vector<int> Leaders(vector<int> arr){
    vector<int> answer;
    
    for(int i=0;i<arr.size();i++){
        bool leader = true;
        for(int j=i+1;j<arr.size();j++){
    
            if(arr[j] > arr[i]){
             leader = false;
             break;
            }
        }
        if(leader){
            answer.push_back(arr[i]);
        }
    }
    return answer;
}
void print(vector<int> arr){
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr = {10, 22, 12, 3, 0, 6};
    cout<<"Input is -> "<<endl;
    print(arr);
    vector<int> ans = Leaders(arr);
    cout<<"Leaders in Array are : "<<endl;
    print(ans);
}