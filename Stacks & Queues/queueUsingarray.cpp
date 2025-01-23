#include<iostream>
using namespace std;

class queue{
    int size;
    int front; 
    int rear;
    int *arr;
    public:
    queue(int size){
        this->size = size;
        this->front = 0;
        this->rear = 0;
        this->arr = new int[size];
    }

    // functions
    void push(int data){
        if(isfull()){
            cout << "queue is full!" << endl;
            return;
        }
        else{
            arr[rear++] = data;
           
        }
    }
    void pop(){
         if(isempty()){
             cout << "can not pop, queue is empty!" << endl;
             return;
         }
         else{
             front++;
             if(front==rear){
                 front = 0;
                 rear = 0;
             }
         }
    }
    bool isempty(){
        if(front==rear){
            return true;
        }
        return false;
    }
    bool isfull(){
       if(rear==size){
           return true;
       }
       return false;
    }
    int frontend(){
        return arr[front];
    }
    int rearend(){
        return arr[rear-1];
    }
};
int main(){
    queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    int front0 = q.frontend();
    cout << "front is : " << front0 << endl;

    int rear0 = q.rearend();
    cout << "rear is : " << rear0 << endl;

    q.pop();
    cout << "isempty : " << q.isempty() << endl;
    cout << "isfull : " << q.isfull() << endl;
}