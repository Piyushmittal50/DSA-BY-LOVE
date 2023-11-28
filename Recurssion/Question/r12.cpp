// subsequences of a string
// number of subsequence : 2^n
#include<iostream>
using namespace std;
void printSub(string str,string out,int i){
// base case
if(i==str.length()){
    cout << out << endl;
    return;
}
// resursive call
   // exclude
printSub(str, out, i + 1);
   // include
out = out + str[i];
printSub(str, out, i + 1);                                                                      
}
int main(){
    string input = "abc";
    string output = "";
    int n = input.length();
    int i = 0;
    printSub(input, output, i);
    return 0;
}