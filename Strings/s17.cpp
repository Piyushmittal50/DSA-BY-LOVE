#include<iostream>
#include<stack>
#include<vector>
using namespace std;
string removeDuplicates(string str){
    stack<char> s;
    vector<bool> seen(256, false);
    for(char ch : str){
        if(!seen[ch]){
            s.push(ch);
            seen[ch] = true;
        }
    }
    string ans = "";
    while(!s.empty()){
        ans += s.top();
        s.pop();
    }
    return ans;
}

string removeDupli(string s){
    string ans = "";
    for (int i = 0; i < s.length();i++){
        int j = 0;
        for (int j = 0; j < i;j++){

        }
    }
}
int main(){
    string name = "abbca";
    string ans = removeDuplicates(name);
    cout << "ans is : " << ans << endl;
}