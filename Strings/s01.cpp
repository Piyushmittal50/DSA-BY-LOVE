// remove all adjacent duplicates
#include<iostream>
#include<string.h>
using namespace std;
string removeDupli(string input,string output){
    int i = 0;

    while(i<input.length()){
        if (output.length() >= 0)
            if (output[output.length() - 1] == input[i])
                output.pop_back();
            else
                output.push_back(input[i]);
        else
        output.push_back(input[i]);
        i++;
    }
    return output;
}
int main(){
    string s = "abbaca";
    string ans = "";
    string output = removeDupli(s, ans);
    cout << output << endl;
}