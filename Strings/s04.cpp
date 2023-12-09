// valid palindome => version 2 => if we delete a character from input string then it now converted into palindrome or not
#include <iostream>
using namespace std;
bool checkPalindrome(string s, int start, int end)
{
    // base case
    if (start >= end)
    {
        return true;
    }
    if (s[start] != s[end])
        return false;

    return checkPalindrome(s, start + 1, end - 1);
}

bool validPalindrome(string s){
    int start = 0;
    int end = s.length() - 1;

    while(start<=end){
    if(s[start]!=s[end]) {
     // ya to ek bar s[start] ko remove karege ya s[end] ko remove karege
     return checkPalindrome(s, start + 1, end) || checkPalindrome(s, start, end - 1);
    }
    else{
     // jab s[start] == s[end]
     start = start + 1;
     end = end - 1;
    }
    }
    return true;
}
int main()
{
    string s = "acbca";
    bool ans = validPalindrome(s);
    if (ans)
        cout << "palindrome" << endl;
    else
        cout << "not palindrome" << endl;
}
