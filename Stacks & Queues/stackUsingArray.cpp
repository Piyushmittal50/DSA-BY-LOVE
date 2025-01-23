#include<iostream>
using namespace std;
class stack{
    int top;
    int *arr; // dynamic array
    int size;

public:
    stack(int size){
        this->top = -1;
        this->size = size;
        this->arr = new int[size];
    }
    // functions
    void push(int data){
       if(isfull()){
           cout << "stack overflow!!" << endl;
           return;
      }
      if(isempty()){
          top = top + 1;
          arr[top] = data;
      }
      else{
          top++;
          arr[top] = data;
      }
    }
    void pop(){
      if(isempty()){
         cout << "stack is underflow!!" << endl;
      }
      else{
          int temp = arr[top];
          top--;
      }
    }

    int peek(){
        return arr[top];
    }
    bool isempty(){
      if(top==-1){
          return true;
      }
      return false;
    }
    bool isfull(){
        if(top==size-1){
            return true;
        }
        return false;
    }
};

int main(){
    stack s(4);
    //s.push(10);
    //s.push(20);
    //s.push(30);
    int top = s.peek();
    cout << "check is full : " << top << endl;

    s.pop();
    top = s.peek();
    cout << "check is full : " << top << endl;

    cout << "isempty : " << s.isempty() << endl;
    cout << "isfull : " << s.isfull() << endl;
}