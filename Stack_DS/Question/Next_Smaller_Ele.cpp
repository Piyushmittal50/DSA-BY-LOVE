#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> nextSmaller(vector<int> &v){
    vector<int> answer(v.size());
   stack<int> s;
    s.push(-1);
      for(int i=v.size()-1 ; i>=0; i--){
            int curr = v[i];

         // apka answer stack mai hai
            while( curr < s.top()){
               s.pop();
            }

         // chota answer mil chuka hai now ans -> store kar lo
            answer[i] = s.top();

         // at last push kardo curr element ko
            s.push(curr); 
       }
       return answer;
}
vector<int> prevSmaller(vector<int> &v){
    vector<int> answer(v.size());
   stack<int> s;
    s.push(-1);
      for(int i=0 ; i<v.size(); i++){
            int curr = v[i];

         // apka answer stack mai hai
            while( curr < s.top()){
               s.pop();
            }

         // chota answer mil chuka hai now ans -> store kar lo
            answer[i] = s.top();

         // at last push kardo curr element ko
            s.push(curr); 
       }
       return answer;
}
int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);

    vector<int> ans01 = nextSmaller(v);
    vector<int> ans02 = prevSmaller(v);
    cout<<"Next Smaller : "<<endl;
    for(auto i:ans01){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"Prev Smaller : "<<endl;
    for(auto i : ans02){
        cout<<i<<" ";
    }
    cout<<endl;
}