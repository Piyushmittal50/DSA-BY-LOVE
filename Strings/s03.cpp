// valid palindorme => version 1
#include<iostream>
using namespace std;
bool checkPalindrome(string s,int start,int end){
// base case
if(start>=end){
    return true;
}
if(s[start]!=s[end])
    return false;

return checkPalindrome(s, start + 1, end - 1);
}
int main(){
string s = "abcbb";
bool ans = checkPalindrome(s,0,s.length()-1);
if(ans)
    cout << "palindrome" << endl;
    else
        cout << "not palindrome" << endl;
}
