#include<iostream>
#include<unordered_map>
using namespace std;
void countWords(string input){
    unordered_map<string, int> mp;
    string temp = "";
    for(char ch : input){
        if(ch!=' '){
            temp += ch;
        }
        else{
            mp[temp]++;
            temp = "";
        }
    }
    mp[temp]++;
    for(auto it: mp){
        cout << it.first << " -> " << it.second << endl;
    }
}
int main(){
    string s = "piyush is my name piyush name";
    countWords(s);
}