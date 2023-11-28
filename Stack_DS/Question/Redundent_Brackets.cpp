#include<iostream>
#include<stack>
using namespace std;
bool check_Redundent(string input){
    stack<char> s;
    
    for(auto ch : input){
     
      // for open brackets || operaters
      if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
        s.push(ch);
      }

      
      else if(!s.empty() && s.top()==')'){
         bool hasoperator = false;

        //  Check for operators between parentheses
        while(!s.empty() && s.top()!='('){
        if(s.top()=='+' || s.top() =='-' || s.top()=='*' || s.top()=='/'){
            hasoperator = true;
           
        }
         s.pop();
        }
         
         if (!s.empty() && s.top() == '(') {
                s.pop(); // Pop the open parenthesis now
            }  

         // If there were no operators between the parentheses, it's redundant
            if (!hasoperator) {
                return true;
            }
        } 
    }
    return false;
}
bool check_Redundent01(string input){
    stack<char> s;
    
    for(auto ch : input){
     
       if( ch==')'){
         bool hasoperator = false;

        //  Check for operators between parentheses
        while(!s.empty() && s.top()!='('){
        if(s.top()=='+' || s.top() =='-' || s.top()=='*' || s.top()=='/'){
            hasoperator = true;
           
        }
         s.pop();
        }
         
        s.pop(); 

        // If there were no operators between the parentheses, it's redundant
            if (!hasoperator) {
                return true;
            }
        } else{
            s.push(ch);
        }
    }
    return false;  // no redendent bracket is found
}
int main(){
   string input = "((a+b))";
   if(check_Redundent01(input)){
    cout<<"Redundent Brackets Found..."<<endl;
   }
   else {
    cout<<"No Redundent Brackets..."<<endl;
   }
}