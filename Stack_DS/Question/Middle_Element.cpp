#include<iostream>
#include<stack>
using namespace std;
int findMiddle(stack<int> &s,int totalsize){

    if(s.size()==(totalsize/2)+1){
        return s.top();  // it just shows you reach at middle element now backtrack
    }

    int topEle = s.top();
    s.pop();

    int middle = findMiddle(s,totalsize);

    // BT
    s.push(topEle);
    return middle;
}
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    int total = s.size();
    int Ele = findMiddle(s,total);
   cout<<"Middle element is : "<<Ele<<endl;
}