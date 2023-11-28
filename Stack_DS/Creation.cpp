#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<char> s;  // stack create
    s.push('L');
    s.push('O');
    s.push('V');// insert element into stack
    s.push('E');

    cout<<"stack top : "<<s.top()<<endl;
    cout<<"number of elements : "<<s.size()<<endl;
    bool isempty = false;
    isempty = s.empty();
    if(isempty){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl;
}