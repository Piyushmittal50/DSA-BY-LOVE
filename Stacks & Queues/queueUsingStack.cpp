#include<iostream>
#include<stack>
using namespace std;
class queue{
    public:
    stack<int> s1, s2;

    // push
    void push(int data){
        // s1 ka data s2 mai push karege
       if(!s1.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
       }
       // now s1 become empty
       // and push karge input data into s1
        s1.push(data);

       // now push back s2 ka data in s1
       if(!s2.empty()){
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
       }
    }

    // pop
    void pop(){
        if(!s1.empty()){
            int temp = s1.top();
            s1.pop();
            cout << temp << " : is poped from queue !" << endl;
        }
    }
    // top
    void top(){
        if (!s1.empty())
        {
            int temp = s1.top();
            cout << temp << " : is the top most ele in queue !" << endl;
        }
    }

    void size(){
        if (!s1.empty())
        {
            cout << "size of queue is : " <<s1.size()<< endl;
        }
    }
};

int main(){
    queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    q.size();
    q.pop();
    q.pop();
    q.size();
}