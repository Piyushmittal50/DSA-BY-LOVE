#include<iostream>
#include<stack>
using namespace std;

int CountRequiredTreaversal(stack<char> s){ 
      // always value present in stack is EVEN
      int count = 0;
      while(s.size()>=2){
       char topEle = s.top();
       s.pop();
       char Ele = s.top();

       if(topEle=='(' && Ele=='(' ||topEle==')' && Ele==')' )  // same bracket
       {
        count +=1;
       }
       else{  // diff bracket
        count +=2;
       }
       s.pop();
      }
      return count;
}

int RemovevalidParenthesis(string input){
    stack<char> s;
     for(int i=0;i<input.length();i++){
        char ch = input[i];

        if(ch=='('){
            s.push(ch);
        }
        else{   // )

           if(!s.empty() && s.top()=='('){
            s.pop();
           }
           else{
            s.push(ch);
           }
        }
     }
    int count = CountRequiredTreaversal(s);
    return count;

   // so now rest of the element present in the stack is invalid brackets 
}
// and now we have to rearrange the rest of the brackets(present in stack) into a valid expression 

//and count the no of times bracket traversal required


int main(){
  string input = ")(())(((";
  int ans = RemovevalidParenthesis(input);
  cout<<"Minimum number of Traversal Required is : "<<ans<<endl;
}