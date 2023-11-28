#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class minStack{
    public:

    vector< pair<int,int> > st;
    void push(int val){
        if(st.empty()){   // if stack is empty
          pair<int,int> p = make_pair(val,val);
          st.push_back(p);
        }
        else{   
           pair<int,int> p;
           p.first = val;
           p.second = min(val,st.back().second);
           st.push_back(p);
        }
    }
    void pop(){
       st.pop_back();
    }
    int top(){
      return st.back().first; 
    }
    int getMin(){
      return st.back().second;
    }
};
int main(){
   minStack obj;
   obj.push(10);
   obj.push(20);
   obj.push(30);
   cout<<"Top Element is : "<<obj.top()<<endl;
   cout<<"Min Ele is : "<<obj.getMin()<<endl;
}