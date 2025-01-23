#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node *next;
};
class stack{
    public:
    node *top;
    stack(){
        top = NULL;
    }
    // functions
    bool isempty()
    {
        return top == NULL;
    }
    void push(int data){
        node *newnode = new node();
        newnode->data = data;
        newnode->next = top;
        top = newnode;
    }
    void pop(){
        if(isempty()){
            cout << "stack is empty, can not pop!" << endl;
            return;
        }
        else{
            node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    int peek(){
        return top->data;
    }
};
int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "top is : " << s.peek() << endl;
    cout << "isempty : " << s.isempty() << endl;
    s.pop();
    cout << "top is : " << s.peek() << endl;
    cout << "isempty : " << s.isempty() << endl;
}