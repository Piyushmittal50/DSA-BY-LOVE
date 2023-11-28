#include<iostream>
using namespace std;

class stack{
    public:
    int *arr; // it is a pointer
    int top;
    int size;

    stack(int size){
        arr = new int[size]; // pointer ko size allocate karva de 
        top = -1;
        this->size = size;
    }

    // Functions

    void push(int data){
        if(size-top>1){
            // space avaliavle
            top++;
            arr[top] = data;
        }
        else{
            // space not avaliavle
            cout<<"Stack Overflow "<<endl;
        }
    }
    void pop(){
         if(top==-1){   // stack is empty
            cout<<"Stack Underflow, cant delete element"<<endl;
         }
         else{
            top--; // stack is not empty
         }
    }
    bool isEmpty(){
         if(top==-1){
            return true;
         }
         else{
            return false;
         }
    }
    int isSize(){
       return top+1;
    }
    int isTop(){
       if(top==-1){
        cout<<"Stack is Empty"<<endl;
       }
       else{
        return arr[top];
       }

       return 0;
    }
};

int main(){
    stack s(10);   // create stack of size 10

    s.push(10);
    s.push(20);  // insertion
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<"Stack top : "<<s.isTop()<<endl;
    s.pop();
     cout<<"Stack top : "<<s.isTop()<<endl;
     while(!s.isEmpty()){
        cout<<s.isTop()<<endl;
        s.pop();
     }
     cout<<"Stack Size : "<<s.isSize()<<endl;
      cout<<"Stack top : "<<s.isTop()<<endl;
}