#include<bits/stdc++.h>
using namespace std;
void insertSorted(stack<int> &s,int ele){
    // base case
    if (s.empty() || ele <= s.top())
    {
        s.push(ele);
        return;
    }
    int topele = s.top();
    s.pop();
    insertSorted(s, ele);
    // backtrack
    s.push(topele);
}

void sortStack(stack<int> &s){
    // base case
    if(s.empty()){
        return;
    }
    int topele = s.top();
    s.pop();
    sortStack(s);
    // backtrack
    insertSorted(s, topele);
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(7);
    s.push(8);
    s.push(5);
    s.push(12);
    s.push(11);
    s.push(14);
    sortStack(s);
    cout << "sorted stack is : " << endl;
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}