#include<iostream>
using namespace std;
bool checkPalindrome(string& input, int start,int end){
   if(start>=end){
       return true;
   }
   if(input[start]!=input[end]){
       return false;
   }
   return checkPalindrome(input, start + 1, end - 1);
}
int main(){
    string input = "kuchhcuk";
    int n = input.length();
    int start = 0;
    int end = n - 1;
    if(checkPalindrome(input, start, end)){
        cout << "given is Palindrome" << endl;
    }
    else{
        cout << "Not palindrome" << endl;
    }
}