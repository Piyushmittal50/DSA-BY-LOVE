#include<iostream>
#include<stack>
using namespace std;

class minSatck{
    int mini = INT_MAX;
    stack<pair<int, int>> s;
    public:
    //Push
    void Push(int data){
 
        if(s.empty()){
            mini = min(mini, data);
            s.push({data, mini});
        }
        else{
            int topMin = s.top().second;
            mini = min(mini, data);
            s.push({data, mini});
        }
       
    }
    void Pop(){
      if(!s.empty()){
          s.pop();
      }
    }
    int getMin(){
        return s.top().second;
    }
};
int main(){
    minSatck s;
    s.Push(10);
    s.Push(20);
    s.Push(5);
    cout << "min is : " << s.getMin() << endl;
    s.Pop();
    cout << "min is : " << s.getMin() << endl;
}