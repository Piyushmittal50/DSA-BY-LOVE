// implement two stack on a single array

#include<iostream>

using namespace std;

class stack{
    public:
    int *arr;
    int size;
    int top1;
    int top2;

    stack(int size){
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;    
    }

    void push1(int data){
        if(top2-top1==1){  // space is not avaliable
         cout<<"Overflow in stack 1"<<endl;
        }
        else{
            top1++;
            arr[top1] = data;
        }
    }

    void pop1(){
          if(top1==-1){
            cout<<"Underflow in stack 1"<<endl;
          }
          else{
            top1--;
          }
    }
    void push2(int data){
       if(top2-top1==1){
        cout<<"Overflow in stack 2"<<endl;
       }
       else{
        top2--;
        arr[top2] = data;
       }
    }
    void pop2(){
      if(top2==size){
        cout<<"Underflow in stack 2"<<endl;
      }
      else{
        top2++;
      }
    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
   stack s(10);
   s.push1(10);
   s.push1(20);
   s.push1(30);
   s.push1(40);
   s.push2(100);
   s.push2(90);
   s.push2(80);

    s.print();

}