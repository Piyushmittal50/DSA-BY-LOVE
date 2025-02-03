// remove all occurence of part substring 
#include<iostream>
#include<string>
using namespace std;
string subString(string input,string part){
    int pos = input.find(part);
    while(pos != string::npos){
        string left = input.substr(0, pos);
        string right = input.substr(pos + part.length(), input.length()-1);
        input = left + right;
        pos = input.find(part);
    }
    return input;
}
int main(){
    string input = "daabcbaabcbc";
    string part = "abc";
    cout << subString(input, part) << endl;
}