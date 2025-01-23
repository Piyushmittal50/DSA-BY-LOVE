#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &s,int target){
    // base case
    if(s.empty()){
        s.push(target);
        return;
    }
    int ele = s.top();
    s.pop();
    insertAtBottom(s, target);
    // backtrack
    s.push(ele);
}
int main(){
    stack<int> s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    int target = 100;
    insertAtBottom(s, target);
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}