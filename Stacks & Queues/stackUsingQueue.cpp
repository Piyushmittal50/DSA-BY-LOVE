#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int> q;
    public:
    // push
    void Push(int data){
        int size = q.size(); // find curr size of queue

        // push new data
        q.push(data);

        for (int i = 0; i < size;i++){
            q.push(q.front());
            q.pop();
        }
    }
    // Pop
    void Pop(){
        q.pop();
    }
    // Top
    int Top(){
        return q.front();
    }
    // Size
    int Size(){
        return q.size();
    }
    bool Isempty(){
        if(q.empty()){
            return true;
        }
        return false;
    }
};

int main(){
    Stack s;
    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.Push(40);

    cout << "top element is : " << s.Top() << endl;
    s.Pop();
    cout << "top element is : " << s.Top() << endl;
}