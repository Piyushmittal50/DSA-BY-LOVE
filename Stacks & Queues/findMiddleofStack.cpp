#include<bits/stdc++.h>
using namespace std;
void findMiddle(stack<int> &s,int size,int count){
    if(count==size/2){
        cout << s.top() << endl;
        return;
    }
    int topele = s.top();
    s.pop();
    findMiddle(s,size, count+1);
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

    findMiddle(s,s.size(),0);
}