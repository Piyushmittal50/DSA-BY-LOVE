#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node *next;
        node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class queue{
    public:
    node *front, *rear;
    queue(){
        front = NULL;
        rear = NULL;
    }
    void push(int data){
        // if Queue is Empty
            if(rear==NULL){
                node *newnode = new node(data);
                front = newnode;
                rear = newnode;
                return;
            }
        // otherwise insert 
            else{
                node* newnode = new node(data);
                rear->next = newnode;
                rear = newnode;
            }
    }
    void pop(){
        // if LL is empty
        if(rear==NULL){
            cout << "LL is empty" << endl;
            return;
        }
        else if(front==rear){
            front = NULL;
            rear = NULL;
            return;
        }
        else{
            // front ko front ->next
            node *curr = front;
            front = front->next;
            if (front == NULL)
            {
                rear = NULL;
            }
            delete curr;
        }
    }
    bool isEmpty(){
        if(rear==NULL){
            return true;
        }
        return false;
    }
    
    int isSize(){
        node *curr = front;
        int i = 0;
        while(curr){
            curr = curr->next;
            i++;
        }
        return i;
    }
    void printQueue()
    {
        node *curr = front;
        while (curr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};
int main(){
    queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Queue size: " << q.isSize() << endl;
    q.printQueue();

    q.pop();
    cout << "Queue after one pop: ";
    q.printQueue();

    q.pop();
    q.pop();
    q.pop(); // Attempting to pop from empty queue

    cout << "Queue size: " << q.isSize() << endl;
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}