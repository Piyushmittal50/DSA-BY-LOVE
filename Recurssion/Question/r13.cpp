#include<iostream>
using namespace std;
// left to right
int lastOccur(string input,char x,int i,int& ans){
    int n = input.length();

    // base case
    if(i==n){
        return ans;
    }
    // processing part
    if(input[i]==x){
        ans = i;
    }
    // recursive relation
    return lastOccur(input, x, i + 1, ans);
}
// right to left 
int Occur(string input,char x , int i){
    if(i<0)
    return -1;
    if(input[i]==x){
        return i;
    }
    return Occur(input, x, i - 1);
}
int main(){
    string input = "abcddeff";
    char x = 'd';
    int i = 0;
    int ans = -1;
    int temp = lastOccur(input, x, i,ans);
    cout << "The last occurence of " << x << " is : " << temp << endl;

    int pop = Occur(input, x, input.length()-1);
    cout << "The last occurence of " << x << " is : " << pop << endl;
}