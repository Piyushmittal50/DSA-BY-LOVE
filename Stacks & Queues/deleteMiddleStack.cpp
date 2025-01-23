#include<bits/stdc++.h>
using namespace std;
void deleteMiddle(stack<int> &s,int size,int count){
    // base case
    if(count==size/2){
        int ele = s.top();
        s.pop();
        cout << "deleted element is : " << ele << endl;
        return;
    }
    int topele = s.top();
    s.pop();

    deleteMiddle(s, size, count + 1);
    // backtrack
    s.push(topele);
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
    s.push(18);
    cout << s.size() << endl;

    deleteMiddle(s, s.size(), 0);
    cout << "after deleting stack elements are : " << endl;
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

}