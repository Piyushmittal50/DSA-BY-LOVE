#include<iostream>
#include<utility>
#include<set>
using namespace std;
void convert(string s){

    int vowels = 0, consonants = 0,extras = 0;
    string lower;
    for (int i = 0; i <= s.length() - 1; i++){
        lower += tolower(s[i]);
    }
    cout << lower << endl;
    for (char ch : lower){
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            vowels++;
        }
        else if (ch >= 'a' && ch <= 'z'){
            consonants++;
        }
        else if(ch==' '){
            extras++;
        }
    }
    cout << "Total vowels : " << vowels << endl;
    cout << "Total consonants : " << consonants << endl;
    cout << "Total extras : " << extras << endl;
}
void Convert(string str){
    set<char> s = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    int vowels = 0, consonants = 0, extras = 0;
  
    for (char ch : str){
        if (s.find(ch)!=s.end()){
            vowels++;
        }
        else if(ch >='a' && ch<='z' || ch>='A' && ch<='Z' && s.find(ch)==s.end()){
            consonants++;
        }
        else{
            extras++;
        }
    }
    cout << "Total vowels : " << vowels << endl;
    cout << "Total consonants : " << consonants << endl;
    cout << "Total extras : " << extras << endl;
}
int main(){
    string s = "Piyush Mittal";
    Convert(s);
}

