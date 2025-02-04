#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string str = "piyush mittal is your name";
    reverse(str.begin(), str.end()); // first reverse the entire str

    int i = 0;
    string temp;
    string final;

    while(i<str.length()){
        if(str[i]!=' '){
            temp += str[i];
            i++;
        }
        else{
            // reverse temp
            reverse(temp.begin(), temp.end());
            final += temp + " ";
            i++;
            temp = "";
        }
    }

    reverse(temp.begin(),temp.end());
    final += temp;
    cout << final<<endl;
}