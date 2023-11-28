// return the middle of the stack element 
#include<iostream>
#include<stack>
using namespace std;
void printmiddle(stack<int> s,int size){
    // empty case
    if(s.size()==0){
        cout<<"there is no element in the stack "<<endl;
        return;
    }
    // base case

    if(s.size()==size/2+1){
        cout<<"Middle Element is : "<<s.top()<<endl;
        return;
    }
    int temp = s.top();
    s.pop();
    // recursive case
    printmiddle(s,size);
    // backtrack
    s.push(temp);
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

    int totalsize = s.size();
    printmiddle(s,totalsize);
    return 0;
}