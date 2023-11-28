#include<iostream>
using namespace std;
class queue{
    // Data members
    int front;
    int rear;
    int *arr;
    int maxSize;
    int currSize;
    public:
     queue(int size){
        front = -1;
        rear = -1;
        maxSize = size;
        arr = new int[maxSize];
        currSize = 0;
     }

    // Member function
     void push(int x){
      
      // check queue is full or not
      if(currSize == maxSize){
        cout<<"queue is full \n Exiting..."<<endl;
        exit(1);
      }
      else{
        arr[rear] = x;
        rear++;
        currSize++;
      }
      
    }

    void pop(){
       if(front==rear){
        cout<<"Queue is Empty"<<endl;
       }
       else{
        front++;
        currSize--;
        if(front==rear){ 
          front = 0;
          rear = 0;
          currSize = 0;
        }
       }
    }

    int frontEle(){
      if(front==rear){
        cout<<"Queue is Empty"<<endl;
        return -1;
      }
      else{
        return arr[front];
      }
    }

    bool isEmpty(){
     if(front==rear) return true;
     else return false;
    }

    int getSize(){
     return currSize;
    }
};

int main(){
    queue s(8);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
   
    cout<<"size : "<<s.getSize()<<endl;
    if(s.isEmpty()){
     cout<<"Stack is Empty!"<<endl;
    }
    else{
        cout<<"Stack is not Empty!"<<endl;
    }
    while(!s.isEmpty()){
        cout<<s.frontEle()<<" "<<endl;
        s.pop();
    
    s.pop();
    cout<<"size is : "<<s.getSize()<<endl;
    
}