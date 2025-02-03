#include<iostream>
#include<stack>
#include<vector>
using namespace std;
string removeDuplicates(string str){

    vector<bool> visit(26, false);
    string ans = "";
    for(char ch : str){
      if(!visit[ch-'a']){
          visit[ch - 'a'] = true;
          ans += ch;
      }
    }
    return ans;
}

int main(){
    string name = "abbca";
    string ans = removeDuplicates(name);
    cout << "ans is : " << ans << endl;
}