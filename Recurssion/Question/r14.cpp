#include<iostream>
using namespace std;
string reverseString(string& input, int start, int end){
   if(start>=end){
       return input;
   }
   swap(input[start], input[end]);

   
   return reverseString(input, start + 1, end - 1);
}
int main(){
    string input = "abcde";
    string output = "";
    int n = input.length();
    int start = 0;
    int end = n - 1;

    cout << "Reverse string is : " << reverseString(input, start, end) << endl;
}