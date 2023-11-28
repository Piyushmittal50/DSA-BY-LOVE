#include<bits/stdc++.h>
#include<stack>
using namespace std;
string findDuplicate(string input){
    stack<char> s;
  for(int i=0;i<input.length();i++){
       char ch = input[i];
       if(s.empty()){
        s.push(ch);
       }
       else{
        if(ch==s.top()){
            s.pop();
        }
        else{
            s.push(ch);
        }
       }
  }
  string ans = "";
  while(!s.empty()){
    ans = ans + s.top();
    s.pop();
  }
  reverse(ans.begin(),ans.end());
  return ans;
}

int main(){
string input = "azxxzy";
string ans = findDuplicate(input);
for(int i=0;i<ans.length();i++){
    cout<<ans[i];
}
cout<<endl;
}