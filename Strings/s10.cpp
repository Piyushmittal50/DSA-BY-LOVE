#include<iostream>
#include<string.h>
#include<stack>
#include<algorithm>
using namespace std;
string reverseName(string s){
    // another string
    string reversed;
    for (int i = s.length()-1; i >=0;i--){
        reversed = reversed + s[i];
    }
    return reversed;
}
string usingStack(string str){
    stack<char> s;
    for(char c : str){
        s.push(c);
    }
    str = "";
    while(!s.empty()){
        str = str + s.top();
        s.pop();
    }
    return str;
}
string usingFunction(string s){
    reverse(s.begin(), s.end());
    return s;
}

string usingTwopointer(string s){
    int start = 0;
    int end = s.length() - 1;
    while(start<=end){
        swap(s[start], s[end]);
        start++;
        end--;
    }
    return s;
}
int main(){
    string name = "piyush mittal";
    string ans = usingTwopointer(name);
    cout << "reversed string is : " << ans << endl;
}