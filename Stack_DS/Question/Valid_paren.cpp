#include<iostream>
#include<stack>
using namespace std;
bool Valid_Parentheses(string input){
   stack<char> s;

   for(int i=0;i<input.length();i++){
    char ch = input[i];

// opening bracket
   if(ch=='(' || ch=='[' || ch=='{'){
    s.push(ch);
   }
// closing bracket
    else{
        if(!s.empty()){
            if((ch==')' && (s.top()=='(')) || (ch=='}' && (s.top()=='{')) || (ch==']' && (s.top()=='['))){
                s.pop();
            }
            else{
                return false;
            }
        }
        else{
            return false; 
        }
    }
   }
   if(s.empty()){
    return true;
   }
   else{
    return false;
   }
}
int main(){
    string input = "([{}])";
    bool ans = Valid_Parentheses(input);
    if(ans){
        cout<<"....Valid... "<<endl;
    }
    else{
        cout<<"...inValid..."<<endl;
    }
}