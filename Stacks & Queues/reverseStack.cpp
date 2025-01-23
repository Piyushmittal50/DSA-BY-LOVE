#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int> &s, int target)
{
    // base case
    if (s.empty())
    {
        s.push(target);
        return;
    }
    int ele = s.top();
    s.pop();
    insertAtBottom(s, target);
    // backtrack
    s.push(ele);
}
void reverseStack(stack<int> &s){
    // base case
    if(s.empty()){
        return;
    }
    int ele = s.top();
    s.pop();
    reverseStack(s);
    // backtrack
    insertAtBottom(s,ele);
}
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
 
    reverseStack(s);
    cout << endl<<"reversed stack element are : ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}