#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;
vector<int> nextSmaller(vector<int> &v){
    vector<int> answer(v.size());
   stack<int> s;
    s.push(-1);
      for(int i=v.size()-1 ; i>=0; i--){
            int curr = v[i];

         // apka answer stack mai hai
            while( s.top()!=-1 && curr <= v[s.top()]){
               s.pop();
            }

         // chota answer mil chuka hai now ans -> store kar lo
            answer[i] = s.top();

         // at last push kardo curr index ko
            s.push(i); 
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
            while(s.top()!=-1 && curr <= v[s.top()]){
               s.pop();
            }

         // chota answer mil chuka hai now ans -> store kar lo
            answer[i] = s.top();

         // at last push kardo curr index ko
            s.push(i); 
       }
       return answer;
}

int getRectangularArea(vector<int> height){

    // step 1 : prevSmaller output
    vector<int> prev = prevSmaller(height);
    
    // step 2 : nextSmaller output

    vector<int> next = nextSmaller(height);
    
    int maxArea = 0;
    int size = height.size();

    for(int i=0;i<height.size();i++){
        int length = height[i];

        if(next[i]==-1){
            next[i] = size;
        }
        int width = next[i] - prev[i] -1 ;
        int area = length * width;

        maxArea = max(maxArea,area);
    }
  return maxArea;
}
int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);

    cout<<"max Area is : "<<getRectangularArea(v)<<endl;

}
