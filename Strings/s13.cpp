#include<iostream>
using namespace std;
bool findSubstring(string text1,string text2){
    int pos = text1.find(text2);
    cout << pos << endl;
    if(pos != string::npos){
        return true;
    }
    return false;
}
int main(){
    string text1 = "concatination";
    string text2 = "nati";
    bool ans = findSubstring(text1, text2);
    if(ans){
        cout << "substring is match__" << endl;
    }
    else{
        cout << "substring is not matched__" << endl;
    }
}