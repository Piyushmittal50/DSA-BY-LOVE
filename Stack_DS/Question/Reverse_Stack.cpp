#include<iostream>
#include<stack>
#include<vector> // auxiliary space
using namespace std;

void insertBottom(stack<int> &s,int target){
   if(s.empty()){
     s.push(target);
     return;
   }
   int topEle = s.top();
    s.pop();
    insertBottom(s,target);

    // BackTrack
    s.push(topEle);
}

void reverse(stack<int> &s){
    // base case while stack becomes empty
    if(s.empty()){
        return;
    }
     int top = s.top();
     s.pop();
     reverse(s);

     // now when it becomes empty 
     insertBottom(s,top);
}


// void reverse(stack<int> &s){
//     vector<int> arr;
//     while(!s.empty()){
//         int topEle = s.top();
//         s.pop();
//         arr.push_back(topEle);
//     }
//     for(auto i : arr){
//         s.push(i);
//     }
// }
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    reverse(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}