#include<iostream>
using namespace std;
bool isPalindrome(string s){

    int start = 0;
    int end = s.length() - 1;
    while (start <= end){
        // alphanumeric character only => 'a-z'  'A-Z'  '0-9'   white space
        if (!isalnum(s[start])){
            start++;
            continue;
        } 
        else if (!isalnum(s[end])){
            end--;
            continue;
        }
        else if (tolower(s[start]) != tolower(s[end])){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
int main(){
    string s = "A man, a plan, a canal: Panama";
    if (isPalindrome(s)){
        cout << "Palindrome" << endl;
    }
    else{
        cout << "not palindrome" << endl;
    }
}
           