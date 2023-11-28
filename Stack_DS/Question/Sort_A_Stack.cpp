#include<iostream>
#include<stack>
using namespace std;
void insertSorted(stack<int> &s,int target){
    if(s.empty()){
        s.push(target);
        return;
    }
    if(s.top()>=target){
        s.push(target);
        return;
    }

    int topEle = s.top();
    s.pop();

    insertSorted(s,target);

    // BackTrack
    s.push(topEle);
}

void sortStack(stack<int> &s){
   // base case
   if(s.empty()){
    return;
   }

   int top = s.top();
   s.pop();

   sortStack(s);
   insertSorted(s,top);
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(7);
    s.push(8);
    s.push(5);
    s.push(12);
    s.push(11);

    sortStack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}